##---------------------------------------------------
## Please set your wxWidgets configuration here
##--------------------------------------------------- 
 
# Here you can define what libraries of wxWidgets you need for your
# application. You can figure out what libraries you need here;
# https://www.wxwidgets.org/manuals/2.8/wx_librarieslist.html
# We need the Find package for wxWidgets to work
# NOTE: if you're using aui, include aui in this required components list.

# It was noticed that when using MinGW gcc it is essential that 'core' is mentioned before 'base'.
find_package(wxWidgets COMPONENTS aui adv html xml net richtext core base REQUIRED)
 
##---------------------------------------------------
## Actual config file starts here
##--------------------------------------------------- 
 
# wxWidgets include (this will do all the magic to configure everything)
include( "${wxWidgets_USE_FILE}" )

# Add source files
set(StrixEditor_SOURCE_FILES StrixEditor.cpp StrixEditor.h Application.cpp Application.h   )

# If we build for windows systems, we also include the resource file
# containing the manifest, icon and other resources
if(WIN32)
 set(StrixEditor_SOURCE_FILES ${StrixEditor_SOURCE_FILES} sample.rc)
endif(WIN32)

# the above paths and defines will be used in this build
add_executable(${CMAKE_PROJECT_NAME} WIN32 ${StrixEditor_SOURCE_FILES})

# Add to StrixEditor to the wxWidgets libraries. These are
# set for  by the find script. Other needed libraries can be added here
target_link_libraries(${CMAKE_PROJECT_NAME} ${wxWidgets_LIBRARIES})