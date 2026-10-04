// MIT

#include "Utility/AxosGameplayTags.h"

namespace AxosTags
{
	namespace ExecutionMode
	{
		UE_DEFINE_GAMEPLAY_TAG(Direct, TEXT("Axos.Execution Mode.Direct"))
		UE_DEFINE_GAMEPLAY_TAG(Abraxas, TEXT("Axos.Execution Mode.Abraxas"))
		UE_DEFINE_GAMEPLAY_TAG(Archon, TEXT("Axos.Execution Mode.Archon"))
	}
	namespace MeasurementSystem
	{
		UE_DEFINE_GAMEPLAY_TAG(Metric, TEXT("Axos.Measurement System.Metric"))
		UE_DEFINE_GAMEPLAY_TAG(Imperial, TEXT("Axos.Measurement System.Imperial"))
	}
	namespace Marker
	{
		namespace State
		{
			UE_DEFINE_GAMEPLAY_TAG(Inactive, TEXT("Axos.Marker.State.Inactive"))
			UE_DEFINE_GAMEPLAY_TAG(Active, TEXT("Axos.Marker.State.Active"))
			UE_DEFINE_GAMEPLAY_TAG(Primary, TEXT("Axos.Marker.State.Primary"))
			UE_DEFINE_GAMEPLAY_TAG(Beacon, TEXT("Axos.Marker.State.Beacon"))
			UE_DEFINE_GAMEPLAY_TAG(Offline, TEXT("Axos.Marker.State.Offline"))
		}
		namespace IconDisplayMode
		{
			UE_DEFINE_GAMEPLAY_TAG(Image, TEXT("Axos.Marker.Icon Display Mode.Image"))
			UE_DEFINE_GAMEPLAY_TAG(Material, TEXT("Axos.Marker.Icon Display Mode.Material"))
		}
	}
}