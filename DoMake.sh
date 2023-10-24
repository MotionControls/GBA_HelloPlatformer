clear
RUNPATH="$PWD"
OUTPATH="$RUNPATH/source/sprites/maps"
RESPATH="$RUNPATH/res"
GRIT="C:/Users/bprso/OneDrive/Desktop/Dev/Tools/grit/grit.exe"
MGBA="C:/Users/bprso/OneDrive/Desktop/Dev/Tools/mGBA/mGba.exe"

<<cm
BG_OPT="-ftc -fh -gt -gB4 -gT -m"

rm -rf $OUTPATH
mkdir -p $OUTPATH

cd $OUTPATH

cm
echo "Running from $RUNPATH"

make && $MGBA -4 "$RUNPATH/a.gba"