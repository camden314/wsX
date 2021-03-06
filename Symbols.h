#pragma once

#include <Windows.h>
#include <stdbool.h>
#include <vector>
#include <string>

#define SPACE 32
#define ARROW 38
#define MSIZE_T 2048

typedef DWORD wptr;
typedef HMODULE wmodule;

typedef int pid_t;
typedef long hook_t;

typedef struct Checkpoint {
    float xpos;
    float rotation;
    float accel;

    float accel2;
    float rotation2;
} Checkpoint;

typedef struct MacroType {
    double xpos;
    int key;
    bool down;
} MType;
typedef struct MacroType2 {
    MType macro;
    int index;
} MType2;

uintptr_t base;
wmodule cocosbase;
void* dispatcherObject;
long scheduler_update;

void* (*scheduler_update_tramp)(void*);
void* (__thiscall *og)(wptr, double);
void(__thiscall* playupdate)(wptr, float);
void* (__thiscall *dispatch_og)(void*, int, bool);
void* (__stdcall *createPlay)(void*);
void* (__thiscall *editorInit)(void*, float);
void (__thiscall *pickup)(void*, int, int);  // = 0x185a20;
//void (*decrement)(void*, int);  // = 0x185b70;
void (__thiscall *practice_og)(void*, bool);
void* (__thiscall *practice_ogCheckpoint)(wptr);
void (__thiscall *practice_ogRemove)(void*);
void (__thiscall *practice_ogDies)(void*, void*, void*);
void (*pauseGame)(long, bool);
void (__thiscall *pasteObjects)(void*, std::string);
void (__thiscall *ogMain)(void*, float);
void (__thiscall *resetOg)(wptr);
void (__thiscall *playDeathEffect)(void*);
void* (__stdcall *sharedApplication)();
void(__thiscall* setAnimInt)(void*, double);
void* (__cdecl* shared_director)(void);
void* (__thiscall* shared_scheduler)(void*);
void(__thiscall* set_time_scale)(void*, float);
void(__thiscall* touches)(void*, void*, void*, unsigned int);

int macro_counter = 0;
int play_record = 4;

int arraySize = MSIZE_T;
int arrayCounter = 0;
MType Macro[MSIZE_T];
MType PracticeMode[MSIZE_T];

bool modifier1 = 0;
bool modifier2 = 0;
bool modifier1_keyDown = 0;
bool modifier2_keyDown = 0;
bool paused = 0;
bool keybinds = true;
bool attached = 0;
bool doIPaste = false;
bool practice_record_mode = false;

bool audioEnabled = false;

int pickupCount = 1;

float SPEED = 1;
float FPS = 60.0;
double practice_playerweight, practice_hiddencheckweight = 0.0f;
double stop_spam_prev = 0.0;
double prev_xpos = 0.0;

std::vector<Checkpoint>* checkpoints;