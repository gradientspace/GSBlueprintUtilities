#include "GSArrayFunctions.h"

template<typename ValueType>
void SortValues(const TArray<ValueType>& InputArray, TArray<ValueType>& SortedArray, TArray<int>& SortingOrder, bool bDecreasing)
{
	int N = InputArray.Num();
	if (N == 0) return;

	struct FValue
	{
		ValueType Value;
		int Index;
		bool operator<(const FValue& Other) const { return Value < Other.Value; }
	};
	TArray<FValue> SortList;
	SortList.Reserve(N);
	for (int k = 0; k < N; ++k)
	{
		SortList.Add(FValue{ InputArray[k], k });
	}
	SortList.StableSort();
	if (bDecreasing)
	{
		Algo::Reverse(SortList);
	}
	SortedArray.Reserve(N);
	SortingOrder.Reserve(N);
	for (const FValue& V : SortList)
	{
		SortedArray.Add(V.Value);
		SortingOrder.Add(V.Index);
	}
}


void UGSArrayBPLibrary::SortFloatArray(const TArray<float>& FloatArray, TArray<float>& SortedArray, TArray<int>& SortingOrder, bool bDecreasing)
{
	SortValues<float>(FloatArray, SortedArray, SortingOrder, bDecreasing);
}

void UGSArrayBPLibrary::SortDoubleArray(const TArray<double>& DoubleArray, TArray<double>& SortedArray, TArray<int>& SortingOrder, bool bDecreasing)
{
	SortValues<double>(DoubleArray, SortedArray, SortingOrder, bDecreasing);
}

void UGSArrayBPLibrary::SortIntArray(const TArray<int>& IntArray, TArray<int>& SortedArray, TArray<int>& SortingOrder, bool bDecreasing)
{
	SortValues<int>(IntArray, SortedArray, SortingOrder, bDecreasing);
}

void UGSArrayBPLibrary::SortStringArray(const TArray<FString>& StringArray, TArray<FString>& SortedArray, TArray<int>& SortingOrder, bool bDecreasing)
{
	SortValues<FString>(StringArray, SortedArray, SortingOrder, bDecreasing);
}
