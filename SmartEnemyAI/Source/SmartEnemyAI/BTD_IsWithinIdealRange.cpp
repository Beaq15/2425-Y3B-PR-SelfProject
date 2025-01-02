// Fill out your copyright notice in the Description page of Project Settings.


#include "BTD_IsWithinIdealRange.h"
#include "AIC_Enemy_Base.h"
#include "Enemy_Base.h"

bool UBTD_IsWithinIdealRange::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	if (AIController)
	{
		AAIC_Enemy_Base* EnemyBaseAI = Cast<AAIC_Enemy_Base>(AIController);
		AEnemy_Base* Enemy = Cast<AEnemy_Base>(AIController->GetPawn());
		if (EnemyBaseAI && Enemy)
		{
			UBlackboardComponent* BlackboardComp = EnemyBaseAI->GetBlackboardComponent();
			if (BlackboardComp)
			{
				float ErrorMargin = 50.0f;
				AActor* TargetActor = Cast<AActor>(BlackboardComp->GetValueAsObject(AttackTarget.SelectedKeyName));
				if (TargetActor)
				{
					float Distance = Enemy->GetDistanceTo(TargetActor);
					float IdealDistance = BlackboardComp->GetValueAsFloat(IdealRange.SelectedKeyName);
					return (Distance - ErrorMargin) <= IdealDistance;
				}
			}
		}

	}
	return false;
}
