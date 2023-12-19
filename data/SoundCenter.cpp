#include "SoundCenter.h"
#include "GAME_ASSERT.h"

using namespace std;

// fixed settings
const int RESERVED_SAMPLES = 16;

SoundCenter::SoundCenter () {}

SoundCenter::~SoundCenter() {
	for(auto &[path, sample_pair] : samples) {
		auto &[sample, insts] = sample_pair;
		al_destroy_sample(sample);
		for(auto inst : insts)
			al_destroy_sample_instance(inst);
	}
}

/**
 * @brief Reserve samples to have default mixer work.
*/
bool
SoundCenter::init() {
	bool res = true;
	res &= al_reserve_samples(RESERVED_SAMPLES);
	res &= (al_get_default_mixer() != nullptr);
	return res;
}

/**
 * @brief The update function searches all sample instances and destroy instances that have finished playing.
 * @details An instance that has finished playing needs to satisfy the following conditions:
 *          * The instance is paused (or stopped).
 *          * The audio track position is 0 (at initial position).
 *          * The instance is not set to loop mode.
*/
void
SoundCenter::update() {
	for(auto &[path, audio_pair] : samples) {
		auto &[sample, insts] = audio_pair;
		for(auto it=insts.begin(); it!=insts.end();) {
			if(al_get_sample_instance_playing(*it)) ++it;
			else if(al_get_sample_instance_position(*it) != 0) ++it;
			else if(al_get_sample_instance_playmode(*it) == ALLEGRO_PLAYMODE_LOOP) ++it;
			else {
				al_destroy_sample_instance(*it);
				it = insts.erase(it);
			}
		}
	}
}

/**
 * @brief Play an audio.
 * @param path the audio file path.
 * @param mode the play mode defined by allegro5.
 * @return The curresponding played ALLEGRO_SAMPLE_INSTANCE* instance.
 * @details For the list of supported play modes, refer to [manual](https://liballeg.org/a5docs/trunk/audio.html#allegro_playmode).
*/
ALLEGRO_SAMPLE_INSTANCE*
SoundCenter::play(const string &path, ALLEGRO_PLAYMODE mode) {
	if(samples.count(path) == 0) {
		ALLEGRO_SAMPLE *sample = al_load_sample(path.c_str());
		GAME_ASSERT(sample != nullptr, "cannot find sample: %s.", path.c_str());
		samples[path] = {sample, {}};
	}
	auto &data = samples[path];
	ALLEGRO_SAMPLE_INSTANCE *instance = al_create_sample_instance(data.first);
	data.second.emplace_back(instance);

	al_set_sample_instance_playmode(instance, mode);
	al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());
	al_play_sample_instance(instance);
	return instance;
}

/**
 * @brief Check is an instance is currently playing.
*/
bool
SoundCenter::is_playing(const ALLEGRO_SAMPLE_INSTANCE *const inst) {
	return al_get_sample_instance_playing(inst);
}

/**
 * @brief Pause or play an audio, depends on its current playing state.
*/
void
SoundCenter::toggle_playing(ALLEGRO_SAMPLE_INSTANCE *inst) {
	bool is_playing = al_get_sample_instance_playing(inst);
	if(is_playing) {
		unsigned int pos = al_get_sample_instance_position(inst);
		al_stop_sample_instance(inst);
		al_set_sample_instance_position(inst, pos);
	} else al_play_sample_instance(inst);
}
