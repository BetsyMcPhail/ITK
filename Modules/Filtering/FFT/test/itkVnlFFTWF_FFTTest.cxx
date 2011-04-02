/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#if defined(_MSC_VER)
#pragma warning ( disable : 4786 )
#endif

#include "itkFFTTest.h"

#if defined(USE_FFTWF)
// Compare FFT using VNL and FFTW Libraries. The test is performed for 2 3d
// array one of them having the same dimension(4,4,4) and the other having
// different dimensions (3,4,5). Images are created with different dimensions
// in the test function based on the second template argument   and  the size
// of these dimensions are taken from the array.The data types used are float
// and double.
int itkVnlFFTWF_FFTTest(int argc, char *argv[])
{
  itk::FFTWGlobalConfiguration::SetPlanRigor(FFTW_EXHAUSTIVE);
  itk::FFTWGlobalConfiguration::SetWriteWisdomCache(true);
  itk::FFTWGlobalConfiguration::SetReadWisdomCache(true);
  if(argc>1)
    {
    itk::FFTWGlobalConfiguration::SetWisdomCacheBase(argv[1]);
    }
  std::cout << "WriteWisdomCache  " << itk::FFTWGlobalConfiguration::GetWriteWisdomCache() << std::endl;
  std::cout << "ReadWisdomCache  " << itk::FFTWGlobalConfiguration::GetReadWisdomCache() << std::endl;
  std::cout << "PlanRigor  " << itk::FFTWGlobalConfiguration::GetPlanRigor() << std::endl;
  std::cout << "WisdomCacheBase " << itk::FFTWGlobalConfiguration::GetWisdomCacheBase()  << std::endl;
  std::cout << "WisdomeFile     " << itk::FFTWGlobalConfiguration::GetWisdomFileDefaultBaseName() << std::endl;
  unsigned int SizeOfDimensions1[] = { 4,4,4 };
  unsigned int SizeOfDimensions2[] = { 3,5,4 };
  int rval = 0;
  std::cerr << "VnlFFTWF:float,1 (4,4,4)" << std::endl;
  if((test_fft_rtc<float,1,
      itk::VnlFFTRealToComplexConjugateImageFilter<float,1> ,
      itk::FFTWRealToComplexConjugateImageFilter<float,1> >(SizeOfDimensions1)) != 0)
    rval++;
  std::cerr << "VnlFFTWF:float,2 (4,4,4)"<< std::endl;
  if((test_fft_rtc<float,2,
      itk::VnlFFTRealToComplexConjugateImageFilter<float,2> ,
      itk::FFTWRealToComplexConjugateImageFilter<float,2> >(SizeOfDimensions1)) != 0)
    rval++;
  std::cerr << "VnlFFTWF:float,3 (4,4,4)"<< std::endl;
  if((test_fft_rtc<float,3,
      itk::VnlFFTRealToComplexConjugateImageFilter<float,3> ,
      itk::FFTWRealToComplexConjugateImageFilter<float,3> >(SizeOfDimensions1)) != 0)
    rval++;
  std::cerr << "VnlFFTWF:float,1 (3,5,4)" << std::endl;
  if((test_fft_rtc<float,1,
      itk::VnlFFTRealToComplexConjugateImageFilter<float,1> ,
      itk::FFTWRealToComplexConjugateImageFilter<float,1> >(SizeOfDimensions2)) != 0)
    rval++;
  std::cerr << "VnlFFTWF:float,2 (3,5,4)"<< std::endl;
  if((test_fft_rtc<float,2,
      itk::VnlFFTRealToComplexConjugateImageFilter<float,2> ,
      itk::FFTWRealToComplexConjugateImageFilter<float,2> >(SizeOfDimensions2)) != 0)
    rval++;
  std::cerr << "VnlFFTWF:float,3 (3,5,4)"<< std::endl;
  if((test_fft_rtc<float,3,
      itk::VnlFFTRealToComplexConjugateImageFilter<float,3> ,
      itk::FFTWRealToComplexConjugateImageFilter<float,3> >(SizeOfDimensions2)) != 0)
    rval++;

  return (rval == 0) ? 0 : -1;
}
#endif