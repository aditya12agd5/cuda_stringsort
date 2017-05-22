CUDA/Thrust GPU Implementation of "[Can GPUs Sort Strings Efficiently?](http://ardeshp2.web.engr.illinois.edu/papers/Aditya13StringSort.pdf)" HiPC'13

By: Aditya Deshpande and P J Narayanan

The code is tested with cuda-7.5

Compile by 

```
make
```

Run code, output written to testcases/

```
bash run_sort.sh
``` 

To run on your own input file

```
./stringSortCvit <input file> <write output flag>


<write ouput flag> = 0 => do not write o/p file
<write output flag> = 1 => write o/p file suffixed with _string_sort_output
```

If you use this code, please cite                                                                   
                                                                                                    
```
@INPROCEEDINGS{DeshpandeCanGpu13, 
  author={Aditya Deshpande and P. J. Narayanan}, 
  booktitle={20th Annual International Conference on High Performance Computing}, 
  title={Can GPUs sort strings efficiently?}, 
  year={2013}, 
  pages={305-313}, 
  month={Dec}}
```
