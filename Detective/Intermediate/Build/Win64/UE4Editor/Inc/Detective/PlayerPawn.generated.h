// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FVector2D;
#ifdef DETECTIVE_PlayerPawn_generated_h
#error "PlayerPawn.generated.h already included, missing '#pragma once' in PlayerPawn.h"
#endif
#define DETECTIVE_PlayerPawn_generated_h

#define Detective_Source_Detective_Character_Player_PlayerPawn_h_23_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execInteract) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Interact(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRotate) \
	{ \
		P_GET_STRUCT(FVector2D,Z_Param__rotation); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Rotate(Z_Param__rotation); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMove) \
	{ \
		P_GET_STRUCT(FVector2D,Z_Param__movement); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Move(Z_Param__movement); \
		P_NATIVE_END; \
	}


#define Detective_Source_Detective_Character_Player_PlayerPawn_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execInteract) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Interact(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRotate) \
	{ \
		P_GET_STRUCT(FVector2D,Z_Param__rotation); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Rotate(Z_Param__rotation); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMove) \
	{ \
		P_GET_STRUCT(FVector2D,Z_Param__movement); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Move(Z_Param__movement); \
		P_NATIVE_END; \
	}


#define Detective_Source_Detective_Character_Player_PlayerPawn_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPlayerPawn(); \
	friend struct Z_Construct_UClass_APlayerPawn_Statics; \
public: \
	DECLARE_CLASS(APlayerPawn, APawn, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Detective"), NO_API) \
	DECLARE_SERIALIZER(APlayerPawn)


#define Detective_Source_Detective_Character_Player_PlayerPawn_h_23_INCLASS \
private: \
	static void StaticRegisterNativesAPlayerPawn(); \
	friend struct Z_Construct_UClass_APlayerPawn_Statics; \
public: \
	DECLARE_CLASS(APlayerPawn, APawn, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Detective"), NO_API) \
	DECLARE_SERIALIZER(APlayerPawn)


#define Detective_Source_Detective_Character_Player_PlayerPawn_h_23_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APlayerPawn(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APlayerPawn) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerPawn); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerPawn); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerPawn(APlayerPawn&&); \
	NO_API APlayerPawn(const APlayerPawn&); \
public:


#define Detective_Source_Detective_Character_Player_PlayerPawn_h_23_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APlayerPawn(APlayerPawn&&); \
	NO_API APlayerPawn(const APlayerPawn&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerPawn); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerPawn); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APlayerPawn)


#define Detective_Source_Detective_Character_Player_PlayerPawn_h_23_PRIVATE_PROPERTY_OFFSET
#define Detective_Source_Detective_Character_Player_PlayerPawn_h_20_PROLOG
#define Detective_Source_Detective_Character_Player_PlayerPawn_h_23_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Detective_Source_Detective_Character_Player_PlayerPawn_h_23_PRIVATE_PROPERTY_OFFSET \
	Detective_Source_Detective_Character_Player_PlayerPawn_h_23_RPC_WRAPPERS \
	Detective_Source_Detective_Character_Player_PlayerPawn_h_23_INCLASS \
	Detective_Source_Detective_Character_Player_PlayerPawn_h_23_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Detective_Source_Detective_Character_Player_PlayerPawn_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Detective_Source_Detective_Character_Player_PlayerPawn_h_23_PRIVATE_PROPERTY_OFFSET \
	Detective_Source_Detective_Character_Player_PlayerPawn_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	Detective_Source_Detective_Character_Player_PlayerPawn_h_23_INCLASS_NO_PURE_DECLS \
	Detective_Source_Detective_Character_Player_PlayerPawn_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> DETECTIVE_API UClass* StaticClass<class APlayerPawn>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Detective_Source_Detective_Character_Player_PlayerPawn_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
