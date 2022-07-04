#pragma once
#include <Windows.h>

#define OFFSET_UWORLD 0xcbf38b8

namespace OFFSETS
{    uintptr_t Gameinstance = 0x1A8;//good
    uintptr_t LocalPlayers = 0x38;//good
    uintptr_t PlayerController = 0x30;//good
    uintptr_t LocalPawn = 0x310;//good
    uintptr_t PlayerState = 0x290;//good
    uintptr_t RootComponet = 0x188;//good
    uintptr_t PersistentLevel = 0x30;//good
    uintptr_t ActorCount = 0xa0;//good
    uintptr_t AActor = 0x98;//good
    uintptr_t CurrentActor = 0x8;//good
    uintptr_t Mesh = 0x2f0;//good
    uintptr_t ObjectID = 0x18;//good
    uintptr_t bADSWhileNotOnGround = 0x4805;
    uintptr_t ZiplinePawnState = 0x1f00;
    uintptr_t Revivefromdbnotime = 0x3fc8;
    uintptr_t LocalRelativeLocation = 0x128;//good
    uintptr_t TeamId = 0x1068;
    uintptr_t LocalActorPos = 0x128;
    uintptr_t ComponetToWorld = 0x240;//0x188
    uintptr_t BoneArray = 0x590;
    uintptr_t Velocity = 0x170;
    uintptr_t fLastSubmitTime = 0x330;
    uintptr_t fLastRenderTimeOnScreen = 0x338;
    uintptr_t CurrentWeapon = 0x7F0;
    uintptr_t LastFireTime = 0xa70;
    uintptr_t LastFireTimeVerified = 0xa74;
    uintptr_t CurrentVehicle = 0x21b8;//0x2158;
    uintptr_t CustomTimeDilation = 0x64;
    uintptr_t bIsDBNO = 0x74A; // 0x6f2;
    uintptr_t bUseGravity = 0x672;


    /*
    intptr_t Gameinstance = 0x1A8;//good
    uintptr_t LocalPlayers = 0x38;//good
    uintptr_t PlayerController = 0x30;//good
    uintptr_t LocalPawn = 0x440;//good
    uintptr_t PlayerState = 0x290;//good
    uintptr_t RootComponet = 0x188;//good
    uintptr_t PersistentLevel = 0x30;//good
    uintptr_t ActorCount = 0xA0;//good
    uintptr_t AActor = 0x98;//good
    uintptr_t CurrentActor = 0x8;//good
    uintptr_t Mesh = 0x2f0;//good
    uintptr_t ObjectID = 0x18;//good
    uintptr_t bADSWhileNotOnGround = 0x4875;
    uintptr_t ZiplinePawnState = 0x1f00;
    uintptr_t Revivefromdbnotime = 0x3fc8;
    uintptr_t LocalRelativeLocation = 0x128;//good
    uintptr_t TeamId = 0x1068;
    uintptr_t LocalActorPos = 0x128;
    uintptr_t ComponetToWorld = 0x188;//0x188
    uintptr_t BoneArray = 0x590;
    uintptr_t Velocity = 0x170;
    uintptr_t fLastSubmitTime = 0x330;
    uintptr_t fLastRenderTimeOnScreen = 0x338;
    uintptr_t CurrentWeapon = 0x790;
    uintptr_t LastFireTime = 0x9CC;
    uintptr_t LastFireTimeVerified = 0x9D0;
    uintptr_t CurrentVehicle = 0x2158;
    uintptr_t CustomTimeDilation = 0x64;
    uintptr_t bIsDBNO = 0x74A; // 0x6f2;
    */
}