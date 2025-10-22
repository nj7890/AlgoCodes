#kadane algorithm
def maxSubArray(arr):
  res=arr[0]
  mxEnding=rr[0]
  for i in range(1,len(arr)):
    mxEnding=max(mxEnding+arr[i],arr[i])
    res=max(res,mxEnding)
  return res
