#!/bin/csh
#
# ************************************
# This script was generated bt Cyber-ShARE's Stg software tool
# Do not modify it manually
# STg will overwrite this script the next time it runs.
# STg development was partially fundedy by NSF Grants CREST HRD-0734825 and CNS-0837556 
# STg was developed by C. Chacon, J. Olaya, R. Romero. May 2009
# Entry point fo execution of Hole's code calls STgShotpoints.
#
# ************************************
# Variables
# ************************************
set exec=/export/home/STg/bin
set userDir=/home/crchacon/jupars
set modelDir=$userDir/Model
set inDir=$userDir
set outDir=$modelDir/OutDir
set vel=$modelDir/Vel
set ttime=$modelDir/Time
set rayCoverage=$modelDir/RayCov
set velPer=$modelDir/VelPer
set smoother1=$modelDir/smoother1
set smoother2=$modelDir/smoother2
#
#
# ************************************
#
# check and add directories
# ************************************
if (-e $modelDir) then
   echo "$modelDir already exists"
else
   mkdir $modelDir
endif
#
if (-e $outDir) then
   echo "$outDir already exists"
else
   mkdir $outDir
endif
#
if (-e $vel) then
   echo "$vel already exists"
else
   mkdir $vel
endif
#
if (-e $ttime) then
   echo "$ttime already exists"
else
   mkdir $ttime
endif
#
if (-e $rayCoverage) then
   echo "$rayCoverage already exists"
else
   mkdir $rayCoverage
endif
#
if (-e $velPer) then
   echo "$velPer already exists"
else
   mkdir $velPer
endif
#
if (-e $smoother1) then
   echo "$smoother1 already exists"
else
   mkdir $smoother1
endif
#
if (-e $smoother2) then
   echo "$smoother2 already exists"
else
   mkdir $smoother2
endif
#
#
# ************************************
# Starting Hole's Code
# ************************************
#
time $exec/vel1d <<$end
$inDir/vzero.par
$end
#
# ************************************
#
set smthx=( 96 48 24 12 6 4 )
set smthy=( 24 24 12 8 4 2 )
set smthz=( 24 16 8 6 2 2 )
set mvax=( 97 47 25 13 7 5 )
set mvay=( 25 25 13 9 5 3 )
set mvaz=( 25 17 9 7 3 3 )
set step = 6
set dimen = 6
set i = 1
set j = 1
while ($i <= $dimen)
while ($j <= $step)
#
# ************************************
#
$userDir/STgShotPoints.sh
#
# ************************************
#
time $exec/tomosm <<$end
$outDir/icov.3d
$outDir/dusum.3d
$outDir/du.3d
231 26 69
1 1 1
$smthx[$i] $smthy[$i] $smthz[$i]
$end
#
# ************************************
#
time $exec/duadd <<$end
$outDir/du.3d
$outDir/vel.3d
$outDir/velnew.3d
231 26 69
1 1 1
$mvax[$i] $mvay[$i] $mvaz[$i]
1
$end
#
# ************************************
#
time $exec/addc <<$end
231 26 69
$outDir/velnew.3d
1.0
$outDir/vel.3d
-1.0
$outDir/dvelnew.3d
$end
#
# ************************************
#
time $exec/addc <<$end
231 26 69
$outDir/vel.3d
1.0
$outDir/dvelnew.3d
1.0
$outDir/dvelnew2.3d
$end
#
# ************************************
#
mv -f $outDir/velnew.3d  $smoother1/velaa$i$j.3d
mv -f $outDir/dvelnew2.3d  $smoother2/dvaa$i$j.3d
cp -f $smoother2/dvaa$i$j.3d $outDir/vel.3d
cp -f $outDir/vel.3d $vel/vel$i$j.3d
cp -f $outDir/icov.3d $rayCoverage/icov$i$j.3d
cp -f $outDir/dusum.3d $velPer/dusum$i$j.3d
cp -f $outDir/time.3d $ttime/time$i$j.3d
@ j = $j + 1
end
#
# ************************************
#
@ i = $i + 1
@ j = 1
end
#
# ************************************
#
