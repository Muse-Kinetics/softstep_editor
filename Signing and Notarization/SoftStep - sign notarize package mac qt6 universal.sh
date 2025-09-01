#!/bin/bash

# This script packages the SoftStep mac application and handles the Apple signing/notarization process.
# - You must use the entitlements included in this directory.
# - Requires environment variables: APPLE_ID, APPLE_APP_PASSWORD, APPLE_TEAM_ID, DEVELOPER_ID

# Load environment variables (run source ~/.env or your credentials script first)
if [[ -z "$DEVELOPER_ID" || -z "$APPLE_KEYCHAIN_PROFILE" ]]; then
    echo "Error: Required environment variables not set"
    echo "Please run: source ~/.env or your credentials script"
    echo "Required: DEVELOPER_ID, APPLE_KEYCHAIN_PROFILE"
    exit 1
fi

# Set to true to enable "press any key to continue" prompts (false = run automatically)
INTERACTIVE_MODE=true

# app_name is the name of the dmg volume
this_year=2024
app_name="SoftStep"
app_name_fp=SoftStep
version=3.0.5

bundle_name=SoftStepEditors
bundle_id="com.keithmcmillen.$bundle_name"
app1="SoftStep Advanced Editor"
app2="SoftStep Basic Editor"
app1_source="../standalone/build-SoftStepAdvanced-Qt_6_9_2_for_macOS-Release/$app1.app"
app2_source="../standalone/build-softstepezpz-Qt_6_9_2_for_macOS-Release/$app2.app"
app1_qml_dir="../standalone/advanced/"
app2_qml_dir="../standalone/ezpz/"
dmg_path=./dmg
dmg_bg="$dmg_path/background.tiff"
dmg_icon="./$app_name.icns"
subfolder_path="./dmg/$app_name"
changelog_source="../CHANGELOG.md"
changelog_dest="$subfolder_path/CHANGELOG.md"
content_source="../Content"
content_dest="$subfolder_path/Content"
app1_path="$subfolder_path/$app1.app"
app2_path="$subfolder_path/$app2.app"
path_to_dqt=~/Qt/6.9.2/macos/bin/macdeployqt
developer_id="$DEVELOPER_ID"
final_dmg_name="./$app_name Mac v$version.dmg"

app1_debug_path="$app1.app/Contents/MacOS/$app1"
app2_debug_path="$app2.app/Contents/MacOS/$app2"

app1_debug_sl="$app1 (debug console)"
app2_debug_sl="$app2 (debug console)"


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

	if [ -L "$subfolder_path/$app1_debug_sl" ] 
	then
		rm -rf "$subfolder_path/$app1_debug_sl"
	fi

	if [ -L "$subfolder_path/$app2_debug_sl" ] 
	then
		rm -rf "$subfolder_path/$app2_debug_sl"
	fi

	if [ -f "$changelog_dest" ] 
	then
		rm -rf "$changelog_dest"
		echo ""
		echo "Cleaning out old changelog..."
		echo ""
	fi

	if [ -f "$content_dest" ] 
	then
	  rm -rf "$content_dest"
	  echo ""
	  echo "Cleaning out old changelog..."
	  echo ""
	fi

	if [ "$INTERACTIVE_MODE" = true ]; then
		echo "Press any key to continue"
		echo
		read -n 1 -s -r -p ""
	fi

	# copy the .app and resources
	\cp -R "$app1_source" "$subfolder_path/"
	\cp -R "$app2_source" "$subfolder_path/"
	\cp -R "$changelog_source" "$subfolder_path/"
	\cp -R "$content_source" "$subfolder_path/"

	echo "Making debug symlinks"

	# echo $app1_debug_sl
	# echo $app2_debug_sl

	if [ "$INTERACTIVE_MODE" = true ]; then
		echo "Press any key to continue"
		echo
		read -n 1 -s -r -p ""
	fi

	cd "$subfolder_path"

	ln -s "$app1_debug_path" "$app1_debug_sl"
	ln -s "$app2_debug_path" "$app2_debug_sl"

	cd "$DIR"

	echo ""
	echo "### - Updating info.plist"
	echo ""
	if [ "$INTERACTIVE_MODE" = true ]; then
		echo "Press any key to continue"
		echo
		read -n 1 -s -r -p ""
	fi

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
	if [ "$INTERACTIVE_MODE" = true ]; then
		echo "Press any key to continue"
		echo
		read -n 1 -s -r -p ""
	fi

	# clean dmg attributes
	xattr -cr "$dmg_path/"

	echo ""
	echo "### - Running macdeployqt - app 1"
	echo ""
	if [ "$INTERACTIVE_MODE" = true ]; then
		echo "Press any key to continue"
		echo
		read -n 1 -s -r -p ""
	fi

	#run macdeployqt
	$path_to_dqt "$app1_path" -verbose=2 -codesign="$developer_id" -qmldir="$app1_qml_dir" -executable="$app1_path/Contents/MacOS/$app1"

	echo ""
	echo "### - Running macdeployqt - app 2"
	echo ""
	if [ "$INTERACTIVE_MODE" = true ]; then
		echo "Press any key to continue"
		echo
		read -n 1 -s -r -p ""
	fi

	$path_to_dqt "$app2_path" -verbose=2 -codesign="$developer_id" -qmldir="$app2_qml_dir" -executable="$app2_path/Contents/MacOS/$app2"

	echo ""
	echo "### - Signing application"
	echo ""
	if [ "$INTERACTIVE_MODE" = true ]; then
		echo "Press any key to continue"
		echo
		read -n 1 -s -r -p ""
	fi

	# sign the code
	codesign -s "$developer_id" --options runtime --timestamp --force --deep --entitlements ./entitlements.mac.plist -f "$app1_path"
	codesign -s "$developer_id" --options runtime --timestamp --force --deep --entitlements ./entitlements.mac.plist -f "$app2_path"

else
	
	echo ""
	echo "### - Setting subfolder icon - fileicon set $subfolder_path/ $dmg_icon"
	echo ""
	if [ "$INTERACTIVE_MODE" = true ]; then
		echo "Press any key to continue"
		echo
		read -n 1 -s -r -p ""
	fi

	fileicon set "$subfolder_path/" "$dmg_icon"


	echo ""
	echo "### - DMG mode - creating DMG and then notarizing..."
	echo ""
	if [ "$INTERACTIVE_MODE" = true ]; then
		echo "Press any key to continue"
		echo
		read -n 1 -s -r -p ""
	fi

fi

echo ""
echo "### - Creating dmg..."
echo ""
if [ "$INTERACTIVE_MODE" = true ]; then
		echo "Press any key to continue"
		echo
		read -n 1 -s -r -p ""
	fi

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


rm "$dmg_path/SoftStem/Icon^M"

echo ""
echo "### - Clean dmg attributes..."
echo ""
if [ "$INTERACTIVE_MODE" = true ]; then
		echo "Press any key to continue"
		echo
		read -n 1 -s -r -p ""
fi

# clean dmg attributes
xattr -cr "$final_dmg_name"

echo ""
echo "### - Signing dmg...."
echo

# sign the dmg
codesign -s "$developer_id" --options runtime --timestamp --force --deep --entitlements ./entitlements.mac.plist -f  "$final_dmg_name"

echo ""
echo "### - Notorizing..."
echo

# submit and notarize

# note - to use the new notarytool you must install a profile/keychain using the following steps in terminal:
# (see https://scriptingosx.com/2021/07/notarize-a-command-line-tool-with-notarytool/)

# 1) Find the profile name by entering: security find-identity -p basic -v
# 2) The profile name is the digits in parenthesis at the end of your Developer ID
# 3) Store the credentials by entering: xcrun notarytool store-credentials --apple-id "$APPLE_ID" --team-id "$APPLE_TEAM_ID"
# 4) Enter the profile name when prompted
# 5) Enter the app specific password (signing / notarization) for the apple id
# 6) Use the profile id from step #4 in the command below

xcrun notarytool submit "$final_dmg_name" --keychain-profile "$APPLE_KEYCHAIN_PROFILE" --wait

