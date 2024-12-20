// Fill out your copyright notice in the Description page of Project Settings.


#include "AIC_Enemy_Base.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

//AAIC_Enemy_Base::AAIC_Enemy_Base()
//{
//    BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
//}
//
//
//void AAIC_Enemy_Base::OnPossess(APawn* InPawn)
//{
//    Super::OnPossess(InPawn);
//
//    // Add a delay (0.2 seconds in the Blueprint)
//    FTimerHandle TimerHandle;
//    GetWorldTimerManager().SetTimer(TimerHandle, [this, InPawn]()
//        {
//            if (behaviorTree)
//            {
//                // Run the behavior tree
//                RunBehaviorTree(behaviorTree);
//
//                // Get the player character and set it as the attack target in the blackboard
//                ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
//                if (PlayerCharacter)
//                {
//                    // Initialize the Blackboard
//                    if (BlackboardComp && behaviorTree->BlackboardAsset)
//                    {
//                        BlackboardComp->InitializeBlackboard(*(behaviorTree->BlackboardAsset));
//                        BlackboardComp->SetValueAsObject(attackTargetKeyName, PlayerCharacter);
//                    }
//                    
//                }
//            }
//        }, 0.2f, false); // Delay of 0.2 seconds
//}

