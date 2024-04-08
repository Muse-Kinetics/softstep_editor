#!/bin/bash

# This script packages the K-Mix mac application and handles the Apple signing/notarization process.
# - You must use the entitlements included in this directory.

# app_name is the name of the dmg volume
this_year=2022
app_name="SoftStep"
app_name_fp=SoftStep
version=3.0.0Y

bundle_name=SoftStepEditors
bundle_id="com.keithmcmillen.$bundle_name"
app1="SoftStep Advanced Editor"
app2="SoftStep Basic Editor"
app1_source="../standalone/build-SoftStepAdvanced-Qt_6_3_2_for_macOS-Release/$app1.app"
app2_source="../standalone/build-softstepezpz-Qt_6_3_2_for_macOS-Release/$app2.app"
app1_qml_dir="../standalone/advanced/"
app2_qml_dir="../standalone/ezpz/"
dmg_path=./dmg
dmg_bg="$dmg_path/background.tiff"
dmg_icon="./$app_name.icns"
subfolder_path="./dmg/$app_name"
changelog_source="../CHANGELOG.md"
changelog_dest="$subfolder_path/CHANGELOG.md"
app1_path="$subfolder_path/$app1.app"
app2_path="$subfolder_path/$app2.app"
path_to_dqt=~/Qt/6.3.2/macos/bin/macdeployqt
developer_id="Developer ID Application: Kesumo, LLC (***REMOVED***)"
final_dmg_name="./$app_name Mac v$version.dmg"


# set current directory to where the script was called from
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
cd "$DIR"

clear

if [ "$1" != -d ] # added -d command line argument to only build the dmg and notarize
then


	echo "$app_name Builder v$version"
	echo 
	echo "Press any key to continue"
	echo
	read -n 1 -s -r -p ""

	if [ -d "$app1_path" ] 
	then
		rm -rf "$app1_path"
		echo ""
		echo "Cleaning out old advanced editor..."
		echo ""
	fi

	if [ -d "$app2_path" ] 
	then
		rm -rf "$app2_path"
		echo ""
		echo "Cleaning out old basic editor..."
		echo ""
	fi

	if [ -f "$changelog_dest" ] 
	then
		rm -rf "$changelog_dest"
		echo ""
		echo "Cleaning out old changelog..."
		echo ""
	fi

	# echo "Press any key to continue"
	# echo
	# read -n 1 -s -r -p ""

	# copy the .app and resources
	\cp -R "$app1_source" "$subfolder_path/"
	\cp -R "$app2_source" "$subfolder_path/"
	\cp -R "$changelog_source" "$subfolder_path/"

	echo ""
	echo "### - Updating info.plist"
	echo ""
	# echo "Press any key to continue"
	# echo
	# read -n 1 -s -r -p ""

	# update info.plist
	plutil -insert "App Category" -string "Music" "$app1_path/Contents/Info.plist"
	plutil -replace "Get Info string" -string "$version, Copyright $this_year Keith McMillen Instruments" "$app1_path/Contents/Info.plist"
	plutil -replace "CFBundleLongVersionString" -string "$app1 $version, Copyright $this_year Keith McMillen Instruments" "$app1_path/Contents/Info.plist"
	plutil -replace "Bundle versions string, short" -string "$version" "$app1_path/Contents/Info.plist"
	plutil -replace "Bundle version" -string "$version" "$app1_path/Contents/Info.plist"

	# update info.plist
	plutil -insert "App Category" -string "Music" "$app2_path/Contents/Info.plist"
	plutil -replace "Get Info string" -string "$version, Copyright $this_year Keith McMillen Instruments" "$app2_path/Contents/Info.plist"
	plutil -replace "CFBundleLongVersionString" -string "$app2 $version, Copyright $this_year Keith McMillen Instruments" "$app2_path/Contents/Info.plist"
	plutil -replace "Bundle versions string, short" -string "$version" "$app2_path/Contents/Info.plist"
	plutil -replace "Bundle version" -string "$version" "$app2_path/Contents/Info.plist"


	echo ""
	echo "### - Cleaning DMG directory attributes"
	echo ""
	# echo "Press any key to continue"
	# echo
	# read -n 1 -s -r -p ""

	# clean dmg attributes
	xattr -cr "$dmg_path/"

	echo ""
	echo "### - Running macdeployqt - app 1"
	echo ""
	# echo "Press any key to continue"
	# echo
	# read -n 1 -s -r -p ""

	#run macdeployqt
	$path_to_dqt "$app1_path" -verbose=2 -codesign="$developer_id" -qmldir="$app1_qml_dir" -executable="$app1_path/Contents/MacOS/$app1"

	echo ""
	echo "### - Running macdeployqt - app 2"
	echo ""
	# echo "Press any key to continue"
	# echo
	# read -n 1 -s -r -p ""

	$path_to_dqt "$app2_path" -verbose=2 -codesign="$developer_id" -qmldir="$app2_qml_dir" -executable="$app2_path/Contents/MacOS/$app2"

	echo ""
	echo "### - Signing QT frameworks"
	echo ""
	# echo "Press any key to continue"
	# echo
	# read -n 1 -s -r -p ""

	#fix parts of deployqt that don't sign correctly
	# codesign -s "$developer_id" --options runtime --timestamp --force --deep --entitlements ./entitlements.mac.plist -f "$app1_path/Contents/Frameworks/QtQuickWidgets.framework/Versions/Current/Resources/QtQuickWidgets.prl"
	# codesign -s "$developer_id" --options runtime --timestamp --force --deep --entitlements ./entitlements.mac.plist -f "$app2_path/Contents/Frameworks/QtGui.framework/Versions/Current/Resources/QtGui.prl"

	# codesign -s "$developer_id" --options runtime --timestamp --force --deep --entitlements ./entitlements.mac.plist -f "$app1_path/Contents/Frameworks/QtPrintSupport.framework/Versions/5/Resources/QtPrintSupport.prl"
	# codesign -s "$developer_id" --options runtime --timestamp --force --deep --entitlements ./entitlements.mac.plist -f "$app1_path/Contents/Frameworks/QtQuickWidgets.framework/Versions/5/Resources/QtQuickWidgets.prl"

	# codesign -s "$developer_id" --options runtime --timestamp --force --deep --entitlements ./entitlements.mac.plist -f "$app2_path/Contents/Frameworks/QtPrintSupport.framework/Versions/5/Resources/QtPrintSupport.prl"
	# #codesign -s "$developer_id" --options runtime --timestamp --force --deep --entitlements ./entitlements.mac.plist -f "$app2_path/Contents/Frameworks/QtQuickWidgets.framework/Versions/5/Resources/QtQuickWidgets.prl"


	echo ""
	echo "### - Signing application"
	echo ""
	# echo "Press any key to continue"
	# echo
	# read -n 1 -s -r -p ""

	# sign the code
	codesign -s "$developer_id" --options runtime --timestamp --force --deep --entitlements ./entitlements.mac.plist -f "$app1_path"
	codesign -s "$developer_id" --options runtime --timestamp --force --deep --entitlements ./entitlements.mac.plist -f "$app2_path"

else
	
	echo ""
	echo "### - Setting subfolder icon - fileicon set $subfolder_path/ $dmg_icon"
	echo ""
	# echo "Press any key to continue"
	# echo
	# read -n 1 -s -r -p ""

	fileicon set "$subfolder_path/" "$dmg_icon"


	echo ""
	echo "### - DMG mode - creating DMG and then notarizing..."
	echo ""
	echo "Press any key to continue"
	echo
	read -n 1 -s -r -p ""

fi

echo ""
echo "### - Creating dmg..."
echo ""
# echo "Press any key to continue"
# echo
# read -n 1 -s -r -p ""

# delete dmg if it already exists
test -f "$final_dmg_name" && rm "$final_dmg_name"

# create-dmg is a utility you can install/update with brew
# if this hangs on "making finder pretty" then you need to terminate the "osascript" process
create-dmg \
  --volname "$app_name" \
  --volicon "$dmg_icon" \
  --background "$dmg_bg" \
  --window-pos 200 120 \
  --window-size 530 380 \
  --icon-size 100 \
  --icon "$app_name" 160 220 \
  --app-drop-link 375 220 \
  --hdiutil-verbose \
  "$final_dmg_name" \
  "$dmg_path/"

# # change folder icon and inspect
# open "$final_dmg_name"
# sleep 4 # wait for image to mount
# open "/Volumes/$app_name"

# echo ""
# echo "### - Inspect volume, eject and press any key to continue"
# echo
# read -n 1 -s -r -p ""

rm "$dmg_path/SoftStem/Icon^M"

echo ""
echo "### - Clean dmg attributes..."
echo ""
# echo "Press any key to continue"
# echo
# read -n 1 -s -r -p ""

# clean dmg attributes
xattr -cr "$final_dmg_name"

echo ""
echo "### - Signing dmg...."
echo

# sign the dmg
codesign -s "Developer ID Application: Kesumo, LLC (***REMOVED***)" --options runtime --timestamp --force --deep --entitlements ./entitlements.mac.plist -f  "$final_dmg_name"

echo ""
echo "### - Notorizing..."
echo

# submit and notarize

# note - to use the new notarytool you must install a profile/keychain using the following steps in terminal:
# (see https://scriptingosx.com/2021/07/notarize-a-command-line-tool-with-notarytool/)

# 1) Find the profile name by entering: security find-identity -p basic -v
# 2) The profile name is the digits in parenthesis at the end of: "Developer ID Application: Kesumo, LLC (***REMOVED***)"
# 3) Store the credentials by entering: xcrun notarytool store-credentials --apple-id "***REMOVED***" --team-id "***REMOVED***"
# 4) Enter the profile name when prompted
# 5) Enter the app specific password (signing / notarization) for the apple id
# 6) Use the profile id from step #4 in the command below

xcrun notarytool submit "$final_dmg_name" --keychain-profile "Andrej" --wait

# deprecated command
#xcrun altool --notarize-app -f "$final_dmg_name" -t osx -u ***REMOVED*** -p ***REMOVED*** -primary-bundle-id $bundle_id


