#!/bin/bash

#-----The '#' followed by SBATCH are SLURM prefixes. They are not comments-----#
#-----It is worth taking note of them when you write your own batch files------#

#SBATCH -D ./
#SBATCH --export=ALL
#SBATCH -p course
#SBATCH -t 5


#ADD INSTRUCTIONS TO LOAD THE MODULES HERE


#ADD COMPILER INSTRUCTION HERE.


#SLURM_NTASKS is given by the -n flag when using sbatch. 
procs=${SLURM_NTASKS:-1}


#RUN THE PROGRAM HERE USING $procs WITH THE -np FLAG.
