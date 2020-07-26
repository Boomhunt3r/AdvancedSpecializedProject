#pragma once

#pragma region UE4 include
#include "CoreMinimal.h"
#include "GameFramework/Character.h"  
#pragma endregion


#pragma region game include
#include "PlayerCharacter.generated.h"  
#pragma endregion

#pragma region forward decleration
class UCapsuleComponent;
class UCameraComponent;
class ULogbook;
class UPlayerAnimation;
#pragma endregion

UCLASS()
class DETECTIVE_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


#pragma region UPROPERTY
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Player Settings")
	float DetectiveViewRange = 0.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Player Settings")
	float InteractRange = 0.0f;
#pragma endregion

#pragma region UFUNCTION
	UFUNCTION(BlueprintCallable, Category = "Player")
	void SetLogbook(ULogbook* Logbook);

	UFUNCTION(BlueprintCallable, Category = "Player")
	void ShowHideLogbook(bool Visible);

	UFUNCTION(BlueprintCallable, Category = "Player")
	void AddLogbookEntry(int ID, FString Text);

	UFUNCTION(BlueprintCallable, Category = "Player")
	void AddImageLogbookEntry(int ID, UTexture2D* Image);

	UFUNCTION(BlueprintCallable, Category = "Player")
	void AddClearLogbookEntry(int ID, UTexture2D* Image);

	UFUNCTION(BlueprintCallable, Category = "Player Action")
	void Interact();

	UFUNCTION(BlueprintCallable, Category = "Player Action")
	void ActivateView(TArray<AActor*> _View);

	UFUNCTION(BlueprintCallable, Category = "Player")
	void LockInput();

	UFUNCTION(BlueprintCallable, Category = "Player")
	void UnlockInput();
#pragma endregion

protected:
#pragma region protected pointer
	ULogbook* m_pLogbook = nullptr;

	UPlayerAnimation* m_pAnimation = nullptr;
#pragma endregion

	void MoveForward(float Value);

	void MoveRight(float Value);

	void TurnAtRate(float Rate);

	void LookUpAtRate(float Rate);

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};
