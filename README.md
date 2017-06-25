# hbbtv_browser
This project is a try of modifying chromium to support hbbtv requirements.
Author Defu Zhen.

1. How to Add Channel related idl files?
   Cp the idl and *.h,*.cpp to third_party/Webkit/Source/core/dom/.
   Modify third_party/Webkit/Source/core/core_idl_file.gni. Add idl files in core_idl_files list.
2. Add below line to HTMLObjectElement.idl
   [NewObject, RaisesException] ChannelList? getChannelConfig(); 
   
