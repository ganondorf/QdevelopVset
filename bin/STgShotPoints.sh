#! /bin/csh
#
# ************************************
# This script was generated bt Cyber-ShARE's Stg software tool
# Do not modify it manually
# STg will overwrite this script the next time it runs.
# STg development was partially fundedy by NSF Grants CREST HRD-0734825 and CNS-0837556 
# STg was developed by C. Chacon, J. Olaya, R. Romero. May 2009
# This script is called by STgMain.sh to run punch & cover for each shot point.
#Project Name: amarillo
#
set exec=/export/home/STg/bin
set userDir=/home/crchacon/jupars
set modelDir=$userDir/Model
set inDir=$userDir
set outDir=$modelDir/OutDir
#
#
time $exec/punch par=$inDir/1.par
#
# ************************************
#
$exec/cover <<$end
/home/crchacon/jupars/1.stat
0
/home/crchacon/jupars/1.pix
0.0
$outDir/time.3d
231 26 69
-71.562 -11.059 0.0
1.0
0. 0. 6.699
$outDir/icov.3d
$outDir/dusum.3d
0
$end
#
# ************************************
echo If you are running on an X window, press CTRL+ Left Mouse click and Select Kill Window to close the output window.
time $exec/punch par=$inDir/2.par
#
# ************************************
#
$exec/cover <<$end
/home/crchacon/jupars/2.stat
0
/home/crchacon/jupars/2.pix
0.0
$outDir/time.3d
231 26 69
-106.996 -14.892 0.0
1.0
0. 0. 6.797
$outDir/icov.3d
$outDir/dusum.3d
1
$end
#
# ************************************
echo If you are running on an X window, press CTRL+ Left Mouse click and Select Kill Window to close the output window.
time $exec/punch par=$inDir/3.par
#
# ************************************
#
$exec/cover <<$end
/home/crchacon/jupars/3.stat
0
/home/crchacon/jupars/3.pix
0.0
$outDir/time.3d
231 26 69
-130.143 -9.671 0.0
1.0
0. 0. 6.765
$outDir/icov.3d
$outDir/dusum.3d
1
$end
#
# ************************************
echo If you are running on an X window, press CTRL+ Left Mouse click and Select Kill Window to close the output window.
time $exec/punch par=$inDir/4.par
#
# ************************************
#
$exec/cover <<$end
/home/crchacon/jupars/4.stat
0
/home/crchacon/jupars/4.pix
0.0
$outDir/time.3d
231 26 69
-161.367 -12.03 0.0
1.0
0. 0. 6.752
$outDir/icov.3d
$outDir/dusum.3d
1
$end
#
# ************************************
echo If you are running on an X window, press CTRL+ Left Mouse click and Select Kill Window to close the output window.
time $exec/punch par=$inDir/5.par
#
# ************************************
#
$exec/cover <<$end
/home/crchacon/jupars/5.stat
0
/home/crchacon/jupars/5.pix
0.0
$outDir/time.3d
231 26 69
-206.64 -15.43 0.0
1.0
0. 0. 6.794
$outDir/icov.3d
$outDir/dusum.3d
1
$end
#
# ************************************
echo If you are running on an X window, press CTRL+ Left Mouse click and Select Kill Window to close the output window.
time $exec/punch par=$inDir/6.par
#
# ************************************
#
$exec/cover <<$end
/home/crchacon/jupars/6.stat
0
/home/crchacon/jupars/6.pix
0.0
$outDir/time.3d
231 26 69
-218.497 -19.796 0.0
1.0
0. 0. 6.766
$outDir/icov.3d
$outDir/dusum.3d
1
$end
#
# ************************************
echo If you are running on an X window, press CTRL+ Left Mouse click and Select Kill Window to close the output window.
time $exec/punch par=$inDir/7.par
#
# ************************************
#
$exec/cover <<$end
/home/crchacon/jupars/7.stat
0
/home/crchacon/jupars/7.pix
0.0
$outDir/time.3d
231 26 69
-14.116 -12.956 0.0
1.0
0. 0. 6.671
$outDir/icov.3d
$outDir/dusum.3d
1
$end
#
# ************************************
echo If you are running on an X window, press CTRL+ Left Mouse click and Select Kill Window to close the output window.
