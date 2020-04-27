// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Detective/Gameplay/Interact/Base/InteractBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInteractBase() {}
// Cross Module References
	DETECTIVE_API UClass* Z_Construct_UClass_AInteractBase_NoRegister();
	DETECTIVE_API UClass* Z_Construct_UClass_AInteractBase();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Detective();
	DETECTIVE_API UFunction* Z_Construct_UFunction_AInteractBase_Interact();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	static FName NAME_AInteractBase_Interact = FName(TEXT("Interact"));
	void AInteractBase::Interact(AActor* OtherActor)
	{
		InteractBase_eventInteract_Parms Parms;
		Parms.OtherActor=OtherActor;
		ProcessEvent(FindFunctionChecked(NAME_AInteractBase_Interact),&Parms);
	}
	void AInteractBase::StaticRegisterNativesAInteractBase()
	{
		UClass* Class = AInteractBase::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Interact", &AInteractBase::execInteract },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AInteractBase_Interact_Statics
	{
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AInteractBase_Interact_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(InteractBase_eventInteract_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AInteractBase_Interact_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AInteractBase_Interact_Statics::NewProp_OtherActor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AInteractBase_Interact_Statics::Function_MetaDataParams[] = {
		{ "Category", "Interact Base" },
		{ "ModuleRelativePath", "Gameplay/Interact/Base/InteractBase.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AInteractBase_Interact_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AInteractBase, nullptr, "Interact", nullptr, nullptr, sizeof(InteractBase_eventInteract_Parms), Z_Construct_UFunction_AInteractBase_Interact_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AInteractBase_Interact_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AInteractBase_Interact_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AInteractBase_Interact_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AInteractBase_Interact()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AInteractBase_Interact_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AInteractBase_NoRegister()
	{
		return AInteractBase::StaticClass();
	}
	struct Z_Construct_UClass_AInteractBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AInteractBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Detective,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AInteractBase_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AInteractBase_Interact, "Interact" }, // 835808268
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInteractBase_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Gameplay/Interact/Base/InteractBase.h" },
		{ "ModuleRelativePath", "Gameplay/Interact/Base/InteractBase.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AInteractBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AInteractBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AInteractBase_Statics::ClassParams = {
		&AInteractBase::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_AInteractBase_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AInteractBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AInteractBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AInteractBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AInteractBase, 1801592843);
	template<> DETECTIVE_API UClass* StaticClass<AInteractBase>()
	{
		return AInteractBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AInteractBase(Z_Construct_UClass_AInteractBase, &AInteractBase::StaticClass, TEXT("/Script/Detective"), TEXT("AInteractBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AInteractBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
