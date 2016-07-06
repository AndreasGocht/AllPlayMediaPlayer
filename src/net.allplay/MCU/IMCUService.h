//-----------------------------------------------------------------------------
// <auto-generated> 
//   This code was generated by a tool. 
// 
//   Changes to this file may cause incorrect behavior and will be lost if  
//   the code is regenerated.
//
//   Tool: AllJoynCodeGenerator.exe
//
//   This tool is located in the Windows 10 SDK and the Windows 10 AllJoyn 
//   Visual Studio Extension in the Visual Studio Gallery.  
//
//   The generated code should be packaged in a Windows 10 C++/CX Runtime  
//   Component which can be consumed in any UWP-supported language using 
//   APIs that are available in Windows.Devices.AllJoyn.
//
//   Using AllJoynCodeGenerator - Invoke the following command with a valid 
//   Introspection XML file and a writable output directory:
//     AllJoynCodeGenerator -i <INPUT XML FILE> -o <OUTPUT DIRECTORY>
// </auto-generated>
//-----------------------------------------------------------------------------
#pragma once

namespace net { namespace allplay { namespace MCU {

public interface class IMCUService
{
public:
    // Implement this function to handle calls to the AdvanceLoopMode method.
    Windows::Foundation::IAsyncOperation<MCUAdvanceLoopModeResult^>^ AdvanceLoopModeAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info );

    // Implement this function to handle calls to the GetCurrentItemUrl method.
    Windows::Foundation::IAsyncOperation<MCUGetCurrentItemUrlResult^>^ GetCurrentItemUrlAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info );

    // Implement this function to handle calls to the PlayItem method.
    Windows::Foundation::IAsyncOperation<MCUPlayItemResult^>^ PlayItemAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info , _In_ Platform::String^ url, _In_ Platform::String^ title, _In_ Platform::String^ artist, _In_ Platform::String^ thumbnailUrl, _In_ int64 duration, _In_ Platform::String^ album, _In_ Platform::String^ genre);

    // Implement this function to handle calls to the SetExternalSource method.
    Windows::Foundation::IAsyncOperation<MCUSetExternalSourceResult^>^ SetExternalSourceAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info , _In_ Platform::String^ name, _In_ bool interruptible, _In_ bool volumeCtrlEnabled);

    // Implement this function to handle calls to the ToggleShuffleMode method.
    Windows::Foundation::IAsyncOperation<MCUToggleShuffleModeResult^>^ ToggleShuffleModeAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info );

    // Implement this function to handle requests for the value of the Version property.
    //
    // Currently, info will always be null, because no information is available about the requestor.
    Windows::Foundation::IAsyncOperation<MCUGetVersionResult^>^ GetVersionAsync(Windows::Devices::AllJoyn::AllJoynMessageInfo^ info);

};

} } } 
