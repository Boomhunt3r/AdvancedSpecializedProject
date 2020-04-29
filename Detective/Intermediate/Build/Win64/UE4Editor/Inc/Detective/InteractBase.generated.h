// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef DETECTIVE_InteractBase_generated_h
#error "InteractBase.generated.h already included, missing '#pragma once' in InteractBase.h"
#endif
#define DETECTIVE_InteractBase_generated_h

#define Detective_Source_Detective_Gameplay_Interact_Base_InteractBase_h_16_RPC_WRAPPERS \
	virtual void Interact_Implementation(AActor* OtherActor); \
 \
	DECLARE_FUNCTION(execInteract) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Interact_Implementation(Z_Param_OtherActor); \
		P_NATIVE_END; \
	}


#define Detective_Source_Detective_Gameplay_Interact_Base_InteractBase_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void Interact_Implementation(AActor* OtherActor); \
 \
	DECLARE_FUNCTION(execInteract) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Interact_Implementation(Z_Param_OtherActor); \
		P_NATIVE_END; \
	}


#define Detective_Source_Detective_Gameplay_Interact_Base_InteractBase_h_16_EVENT_PARMS \
	struct InteractBase_eventInteract_Parms \
	{ \
		AActor* OtherActor; \
	};


#define Detective_Source_Detective_Gameplay_Interact_Base_InteractBase_h_16_CALLBACK_WRAPPERS
#define Detective_Source_Detective_Gameplay_Interact_Base_InteractBase_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAInteractBase(); \
	friend struct Z_Construct_UClass_AInteractBase_Statics; \
public: \
	DECLARE_CLASS(AInteractBase, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Detective"), NO_API) \
	DECLARE_SERIALIZER(AInteractBase)


#define Detective_Source_Detective_Gameplay_Interact_Base_InteractBase_h_16_INCLASS \
private: \
	static void StaticRegisterNativesAInteractBase(); \
	friend struct Z_Construct_UClass_AInteractBase_Statics; \
public: \
	DECLARE_CLASS(AInteractBase, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Detective"), NO_API) \
	DECLARE_SERIALIZER(AInteractBase)


#define Detective_Source_Detective_Gameplay_Interact_Base_InteractBase_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AInteractBase(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AInteractBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AInteractBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AInteractBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AInteractBase(AInteractBase&&); \
	NO_API AInteractBase(const AInteractBase&); \
public:


#define Detective_Source_Detective_Gameplay_Interact_Base_InteractBase_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AInteractBase(AInteractBase&&); \
	NO_API AInteractBase(const AInteractBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AInteractBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AInteractBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AInteractBase)


#define Detective_Source_Detective_Gameplay_Interact_Base_InteractBase_h_16_PRIVATE_PROPERTY_OFFSET
#define Detective_Source_Detective_Gameplay_Interact_Base_InteractBase_h_13_PROLOG \
	Detective_Source_Detective_Gameplay_Interact_Base_InteractBase_h_16_EVENT_PARMS


#define Detective_Source_Detective_Gameplay_Interact_Base_InteractBase_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Detective_Source_Detective_Gameplay_Interact_Base_InteractBase_h_16_PRIVATE_PROPERTY_OFFSET \
	Detective_Source_Detective_Gameplay_Interact_Base_InteractBase_h_16_RPC_WRAPPERS \
	Detective_Source_Detective_Gameplay_Interact_Base_InteractBase_h_16_CALLBACK_WRAPPERS \
	Detective_Source_Detective_Gameplay_Interact_Base_InteractBase_h_16_INCLASS \
	Detective_Source_Detective_Gameplay_Interact_Base_InteractBase_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Detective_Source_Detective_Gameplay_Interact_Base_InteractBase_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Detective_Source_Detective_Gameplay_Interact_Base_InteractBase_h_16_PRIVATE_PROPERTY_OFFSET \
	Detective_Source_Detective_Gameplay_Interact_Base_InteractBase_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	Detective_Source_Detective_Gameplay_Interact_Base_InteractBase_h_16_CALLBACK_WRAPPERS \
	Detective_Source_Detective_Gameplay_Interact_Base_InteractBase_h_16_INCLASS_NO_PURE_DECLS \
	Detective_Source_Detective_Gameplay_Interact_Base_InteractBase_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> DETECTIVE_API UClass* StaticClass<class AInteractBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Detective_Source_Detective_Gameplay_Interact_Base_InteractBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
