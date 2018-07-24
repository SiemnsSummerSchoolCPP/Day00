# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.Exe.Debug:
PostBuild.Game.Debug: /Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/Debug/Exe
PostBuild.Game.Debug: /Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/Debug/Exe
/Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/Debug/Exe:\
	/Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/Debug/libGame.a\
	/Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/Debug/libGame.a
	/bin/rm -f /Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/Debug/Exe


PostBuild.Game.Debug:
/Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/Debug/libGame.a:
	/bin/rm -f /Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/Debug/libGame.a


PostBuild.Exe.Release:
PostBuild.Game.Release: /Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/Release/Exe
PostBuild.Game.Release: /Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/Release/Exe
/Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/Release/Exe:\
	/Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/Release/libGame.a\
	/Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/Release/libGame.a
	/bin/rm -f /Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/Release/Exe


PostBuild.Game.Release:
/Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/Release/libGame.a:
	/bin/rm -f /Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/Release/libGame.a


PostBuild.Exe.MinSizeRel:
PostBuild.Game.MinSizeRel: /Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/MinSizeRel/Exe
PostBuild.Game.MinSizeRel: /Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/MinSizeRel/Exe
/Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/MinSizeRel/Exe:\
	/Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/MinSizeRel/libGame.a\
	/Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/MinSizeRel/libGame.a
	/bin/rm -f /Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/MinSizeRel/Exe


PostBuild.Game.MinSizeRel:
/Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/MinSizeRel/libGame.a:
	/bin/rm -f /Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/MinSizeRel/libGame.a


PostBuild.Exe.RelWithDebInfo:
PostBuild.Game.RelWithDebInfo: /Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/RelWithDebInfo/Exe
PostBuild.Game.RelWithDebInfo: /Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/RelWithDebInfo/Exe
/Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/RelWithDebInfo/Exe:\
	/Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/RelWithDebInfo/libGame.a\
	/Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/RelWithDebInfo/libGame.a
	/bin/rm -f /Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/RelWithDebInfo/Exe


PostBuild.Game.RelWithDebInfo:
/Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/RelWithDebInfo/libGame.a:
	/bin/rm -f /Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/RelWithDebInfo/libGame.a




# For each target create a dummy ruleso the target does not have to exist
/Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/Debug/libGame.a:
/Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/MinSizeRel/libGame.a:
/Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/RelWithDebInfo/libGame.a:
/Users/unicornslayer/Projects/summerSchoolPersonal/Day00/Ex03_DungeonCrawl/bin/Release/libGame.a:
