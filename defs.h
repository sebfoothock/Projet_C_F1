#ifndef PROJET_F1_C_DEFS_H
#define PROJET_F1_C_DEFS_H

#define SIG_RACE_START (SIGUSR1)
#define SIG_RACE_STOP (SIGUSR2)

static const unsigned int test_times[] = {2, 2, 2};
static const unsigned int qualif_times[] = {5, 4, 3};
static const int race_laps = 50;
static const int simulation_divider = 1;

/* Valid status for pilote.status */
typedef enum status status;
enum status {
    driving,
    pitstop,
    out,
	eliminated,
    end
};

/* A queue of laps, each the time by sector and a pointer to the next lap */
typedef struct lap lap;
struct lap {
	lap* nextlap;
	float time_s1;
	float time_s2;
	float time_s3;
    float time_pit;
};

/* Best time by sector and best lap time */
typedef struct bestlap bestlap;
struct bestlap {
	float best_s1;
	float best_s2;
	float best_s3;
	float best_lap;
};

/* The scoreboard for each pilote */
typedef struct scoreboard scoreboard;
struct scoreboard {
	int car_id;
	lap* races[7]; // Point the first lap of each race
	lap* last_lap[7]; //Point to races[i]->nextLap->nextLap->...->nextLap, the current lap
	bestlap bestlaps[7];
};

/* Shared structure, used by pilotes to give infos on their race */
typedef struct pilote pilote;
struct pilote {
	int car_id;
	int cli_idx;
	int lap_cnt;
	int sector;
    int position;
	float time;
	enum status status;
	int has_changed;
	scoreboard* scores;
};
typedef struct rank_item rank_item;
struct rank_item{
    pilote* car;
    float bestlap;
};

#endif