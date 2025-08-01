//===========================================================================//
// GodotSteam MultiplayerPeer - godotsteam_id.h
//===========================================================================//
//
// Copyright (c) 2017-Current | Ryan Leverenz and Contributors
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
//===========================================================================//

#ifndef GODOTSTEAM_ID
#define GODOTSTEAM_ID


// Turn off MSVC-only warning about strcpy
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable : 4996)
#pragma warning(disable : 4828)
#endif


// Include GodotSteam's Steam SDK headers
#include "../godotsteam/sdk/public/steam/steam_api_flat.h"

// Include Godot headers
#include "core/os/os.h"


class SteamID : public RefCounted {
	GDCLASS(SteamID, RefCounted);

	CSteamID steam_id;


public:

	inline bool operator==(const SteamID &val) const { return steam_id == val.steam_id; }
	inline bool operator!=(const SteamID &val) const { return steam_id != val.steam_id; }


	// STEAMWORKS API ENUMS
	enum AccountType {
		// Found in steamclientpublic.h
		ACCOUNT_TYPE_INVALID = k_EAccountTypeInvalid,
		ACCOUNT_TYPE_INDIVIDUAL = k_EAccountTypeIndividual,
		ACCOUNT_TYPE_MULTISEAT = k_EAccountTypeMultiseat,
		ACCOUNT_TYPE_GAME_SERVER = k_EAccountTypeGameServer,
		ACCOUNT_TYPE_ANON_GAME_SERVER = k_EAccountTypeAnonGameServer,
		ACCOUNT_TYPE_PENDING = k_EAccountTypePending,
		ACCOUNT_TYPE_CONTENT_SERVER = k_EAccountTypeContentServer,
		ACCOUNT_TYPE_CLAN = k_EAccountTypeClan,
		ACCOUNT_TYPE_CHAT = k_EAccountTypeChat,
		ACCOUNT_TYPE_CONSOLE_USER = k_EAccountTypeConsoleUser,
		ACCOUNT_TYPE_ANON_USER = k_EAccountTypeAnonUser
	};
	enum Universe {
		// Found in steamuniverse.h
		UNIVERSE_INVALID = k_EUniverseInvalid,
		UNIVERSE_PUBLIC = k_EUniversePublic,
		UNIVERSE_BETA = k_EUniverseBeta,
		UNIVERSE_INTERNAL = k_EUniverseInternal,
		UNIVERSE_DEV = k_EUniverseDev
	};


	// INTERNAL
	SteamID() { steam_id = CSteamID(); }
	SteamID(CSteamID this_steam_id) { steam_id = this_steam_id; }
	
	void from_CSteamID(CSteamID i) { steam_id = i; }
	void setData(CSteamID new_steam_id) { steam_id = new_steam_id; }

	// FUNCTIONS
	void from_int(uint64_t new_steam_id){ steam_id.SetFromUint64(new_steam_id); }

	uint32 get_account_id() { return steam_id.GetAccountID(); }
	uint32 get_un_account_instance() { return steam_id.GetUnAccountInstance(); }
	AccountType get_account_type() { return AccountType(steam_id.GetEAccountType()); }
	Universe get_universe() { return Universe(steam_id.GetEUniverse()); }

	uint64_t to_int(){ return steam_id.ConvertToUint64(); }


	static void _bind_methods();

};


VARIANT_ENUM_CAST(SteamID::AccountType);
VARIANT_ENUM_CAST(SteamID::Universe);


#endif // GODOTSTEAM_ID