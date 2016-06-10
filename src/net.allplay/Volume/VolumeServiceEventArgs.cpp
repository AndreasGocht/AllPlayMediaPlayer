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
#include "pch.h"

using namespace concurrency;
using namespace Microsoft::WRL;
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Devices::AllJoyn;
using namespace net::allplay::Control::Volume;
namespace net { namespace allplay { namespace Control { namespace Volume {

// Methods
VolumeAdjustVolumeCalledEventArgs::VolumeAdjustVolumeCalledEventArgs(
    _In_ AllJoynMessageInfo^ info,
    _In_ int16 interfaceMemberDelta)
    : m_raised(false),
    m_completionsRequired(0),
    m_messageInfo(info),
    m_interfaceMemberDelta(interfaceMemberDelta)
{
	m_result = VolumeAdjustVolumeResult::CreateFailureResult(ER_NOT_IMPLEMENTED);
}

Deferral^ VolumeAdjustVolumeCalledEventArgs::GetDeferral()
{
    std::lock_guard<std::mutex> lockGuard(m_lock);
    if (m_raised)
    {
        // Cannot ask for a deferral after the event handler has returned.
        throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
    }

    m_completionsRequired++;
    auto handler = ref new DeferralCompletedHandler(this, &VolumeAdjustVolumeCalledEventArgs::Complete);
    return ref new Deferral(handler);
}

void VolumeAdjustVolumeCalledEventArgs::InvokeAllFinished()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        m_raised = true;
        invokeNeeded = (m_completionsRequired == 0);
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void VolumeAdjustVolumeCalledEventArgs::Complete()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        if (m_completionsRequired == 0)
        {
            // This should never happen since Complete() should only be called by Windows.Foundation.Deferral
            // which will only invoke our completion handler once.
            throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
        }
        m_completionsRequired--;
        invokeNeeded = (m_raised && (m_completionsRequired == 0));
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void VolumeAdjustVolumeCalledEventArgs::InvokeCompleteHandler()
{
    if (m_result->Status == ER_NOT_IMPLEMENTED)
    {
        throw Exception::CreateException(E_NOTIMPL, "No handlers are registered for AdjustVolumeCalled.");
    }
    else
    {
        m_tce.set(m_result);
    }
}

VolumeAdjustVolumePercentCalledEventArgs::VolumeAdjustVolumePercentCalledEventArgs(
    _In_ AllJoynMessageInfo^ info,
    _In_ double interfaceMemberChange)
    : m_raised(false),
    m_completionsRequired(0),
    m_messageInfo(info),
    m_interfaceMemberChange(interfaceMemberChange)
{
	m_result = VolumeAdjustVolumePercentResult::CreateFailureResult(ER_NOT_IMPLEMENTED);
}

Deferral^ VolumeAdjustVolumePercentCalledEventArgs::GetDeferral()
{
    std::lock_guard<std::mutex> lockGuard(m_lock);
    if (m_raised)
    {
        // Cannot ask for a deferral after the event handler has returned.
        throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
    }

    m_completionsRequired++;
    auto handler = ref new DeferralCompletedHandler(this, &VolumeAdjustVolumePercentCalledEventArgs::Complete);
    return ref new Deferral(handler);
}

void VolumeAdjustVolumePercentCalledEventArgs::InvokeAllFinished()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        m_raised = true;
        invokeNeeded = (m_completionsRequired == 0);
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void VolumeAdjustVolumePercentCalledEventArgs::Complete()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        if (m_completionsRequired == 0)
        {
            // This should never happen since Complete() should only be called by Windows.Foundation.Deferral
            // which will only invoke our completion handler once.
            throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
        }
        m_completionsRequired--;
        invokeNeeded = (m_raised && (m_completionsRequired == 0));
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void VolumeAdjustVolumePercentCalledEventArgs::InvokeCompleteHandler()
{
    if (m_result->Status == ER_NOT_IMPLEMENTED)
    {
        throw Exception::CreateException(E_NOTIMPL, "No handlers are registered for AdjustVolumePercentCalled.");
    }
    else
    {
        m_tce.set(m_result);
    }
}

// Readable Properties
VolumeGetEnabledRequestedEventArgs::VolumeGetEnabledRequestedEventArgs(
    _In_ AllJoynMessageInfo^ info)
    : m_raised(false),
    m_completionsRequired(0),
    m_messageInfo(info)
{
	m_result = VolumeGetEnabledResult::CreateFailureResult(ER_NOT_IMPLEMENTED);
}

Deferral^ VolumeGetEnabledRequestedEventArgs::GetDeferral()
{
    std::lock_guard<std::mutex> lockGuard(m_lock);
    if (m_raised)
    {
        // Cannot ask for a deferral after the event handler has returned.
        throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
    }

    m_completionsRequired++;
    auto handler = ref new DeferralCompletedHandler(this, &VolumeGetEnabledRequestedEventArgs::Complete);
    return ref new Deferral(handler);
}

void VolumeGetEnabledRequestedEventArgs::InvokeAllFinished()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        m_raised = true;
        invokeNeeded = (m_completionsRequired == 0);
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void VolumeGetEnabledRequestedEventArgs::Complete()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        if (m_completionsRequired == 0)
        {
            // This should never happen since Complete() should only be called by Windows.Foundation.Deferral
            // which will only invoke our completion handler once.
            throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
        }
        m_completionsRequired--;
        invokeNeeded = (m_raised && (m_completionsRequired == 0));
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void VolumeGetEnabledRequestedEventArgs::InvokeCompleteHandler()
{
    if (m_result->Status == ER_NOT_IMPLEMENTED)
    {
        throw Exception::CreateException(E_NOTIMPL, "No handlers are registered for GetEnabledRequested.");
    }
    else
    {
        m_tce.set(m_result);
    }
}

VolumeGetMuteRequestedEventArgs::VolumeGetMuteRequestedEventArgs(
    _In_ AllJoynMessageInfo^ info)
    : m_raised(false),
    m_completionsRequired(0),
    m_messageInfo(info)
{
	m_result = VolumeGetMuteResult::CreateFailureResult(ER_NOT_IMPLEMENTED);
}

Deferral^ VolumeGetMuteRequestedEventArgs::GetDeferral()
{
    std::lock_guard<std::mutex> lockGuard(m_lock);
    if (m_raised)
    {
        // Cannot ask for a deferral after the event handler has returned.
        throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
    }

    m_completionsRequired++;
    auto handler = ref new DeferralCompletedHandler(this, &VolumeGetMuteRequestedEventArgs::Complete);
    return ref new Deferral(handler);
}

void VolumeGetMuteRequestedEventArgs::InvokeAllFinished()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        m_raised = true;
        invokeNeeded = (m_completionsRequired == 0);
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void VolumeGetMuteRequestedEventArgs::Complete()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        if (m_completionsRequired == 0)
        {
            // This should never happen since Complete() should only be called by Windows.Foundation.Deferral
            // which will only invoke our completion handler once.
            throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
        }
        m_completionsRequired--;
        invokeNeeded = (m_raised && (m_completionsRequired == 0));
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void VolumeGetMuteRequestedEventArgs::InvokeCompleteHandler()
{
    if (m_result->Status == ER_NOT_IMPLEMENTED)
    {
        throw Exception::CreateException(E_NOTIMPL, "No handlers are registered for GetMuteRequested.");
    }
    else
    {
        m_tce.set(m_result);
    }
}

VolumeGetVersionRequestedEventArgs::VolumeGetVersionRequestedEventArgs(
    _In_ AllJoynMessageInfo^ info)
    : m_raised(false),
    m_completionsRequired(0),
    m_messageInfo(info)
{
	m_result = VolumeGetVersionResult::CreateFailureResult(ER_NOT_IMPLEMENTED);
}

Deferral^ VolumeGetVersionRequestedEventArgs::GetDeferral()
{
    std::lock_guard<std::mutex> lockGuard(m_lock);
    if (m_raised)
    {
        // Cannot ask for a deferral after the event handler has returned.
        throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
    }

    m_completionsRequired++;
    auto handler = ref new DeferralCompletedHandler(this, &VolumeGetVersionRequestedEventArgs::Complete);
    return ref new Deferral(handler);
}

void VolumeGetVersionRequestedEventArgs::InvokeAllFinished()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        m_raised = true;
        invokeNeeded = (m_completionsRequired == 0);
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void VolumeGetVersionRequestedEventArgs::Complete()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        if (m_completionsRequired == 0)
        {
            // This should never happen since Complete() should only be called by Windows.Foundation.Deferral
            // which will only invoke our completion handler once.
            throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
        }
        m_completionsRequired--;
        invokeNeeded = (m_raised && (m_completionsRequired == 0));
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void VolumeGetVersionRequestedEventArgs::InvokeCompleteHandler()
{
    if (m_result->Status == ER_NOT_IMPLEMENTED)
    {
        throw Exception::CreateException(E_NOTIMPL, "No handlers are registered for GetVersionRequested.");
    }
    else
    {
        m_tce.set(m_result);
    }
}

VolumeGetVolumeRequestedEventArgs::VolumeGetVolumeRequestedEventArgs(
    _In_ AllJoynMessageInfo^ info)
    : m_raised(false),
    m_completionsRequired(0),
    m_messageInfo(info)
{
	m_result = VolumeGetVolumeResult::CreateFailureResult(ER_NOT_IMPLEMENTED);
}

Deferral^ VolumeGetVolumeRequestedEventArgs::GetDeferral()
{
    std::lock_guard<std::mutex> lockGuard(m_lock);
    if (m_raised)
    {
        // Cannot ask for a deferral after the event handler has returned.
        throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
    }

    m_completionsRequired++;
    auto handler = ref new DeferralCompletedHandler(this, &VolumeGetVolumeRequestedEventArgs::Complete);
    return ref new Deferral(handler);
}

void VolumeGetVolumeRequestedEventArgs::InvokeAllFinished()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        m_raised = true;
        invokeNeeded = (m_completionsRequired == 0);
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void VolumeGetVolumeRequestedEventArgs::Complete()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        if (m_completionsRequired == 0)
        {
            // This should never happen since Complete() should only be called by Windows.Foundation.Deferral
            // which will only invoke our completion handler once.
            throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
        }
        m_completionsRequired--;
        invokeNeeded = (m_raised && (m_completionsRequired == 0));
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void VolumeGetVolumeRequestedEventArgs::InvokeCompleteHandler()
{
    if (m_result->Status == ER_NOT_IMPLEMENTED)
    {
        throw Exception::CreateException(E_NOTIMPL, "No handlers are registered for GetVolumeRequested.");
    }
    else
    {
        m_tce.set(m_result);
    }
}

VolumeGetVolumeRangeRequestedEventArgs::VolumeGetVolumeRangeRequestedEventArgs(
    _In_ AllJoynMessageInfo^ info)
    : m_raised(false),
    m_completionsRequired(0),
    m_messageInfo(info)
{
	m_result = VolumeGetVolumeRangeResult::CreateFailureResult(ER_NOT_IMPLEMENTED);
}

Deferral^ VolumeGetVolumeRangeRequestedEventArgs::GetDeferral()
{
    std::lock_guard<std::mutex> lockGuard(m_lock);
    if (m_raised)
    {
        // Cannot ask for a deferral after the event handler has returned.
        throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
    }

    m_completionsRequired++;
    auto handler = ref new DeferralCompletedHandler(this, &VolumeGetVolumeRangeRequestedEventArgs::Complete);
    return ref new Deferral(handler);
}

void VolumeGetVolumeRangeRequestedEventArgs::InvokeAllFinished()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        m_raised = true;
        invokeNeeded = (m_completionsRequired == 0);
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void VolumeGetVolumeRangeRequestedEventArgs::Complete()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        if (m_completionsRequired == 0)
        {
            // This should never happen since Complete() should only be called by Windows.Foundation.Deferral
            // which will only invoke our completion handler once.
            throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
        }
        m_completionsRequired--;
        invokeNeeded = (m_raised && (m_completionsRequired == 0));
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void VolumeGetVolumeRangeRequestedEventArgs::InvokeCompleteHandler()
{
    if (m_result->Status == ER_NOT_IMPLEMENTED)
    {
        throw Exception::CreateException(E_NOTIMPL, "No handlers are registered for GetVolumeRangeRequested.");
    }
    else
    {
        m_tce.set(m_result);
    }
}

// Writable Properties
VolumeSetMuteRequestedEventArgs::VolumeSetMuteRequestedEventArgs(
    _In_ AllJoynMessageInfo^ info,
    _In_ bool value)
    : m_raised(false),
    m_completionsRequired(0),
    m_messageInfo(info),
    m_value(value)
{
	m_result = VolumeSetMuteResult::CreateFailureResult(ER_NOT_IMPLEMENTED);
}

Deferral^ VolumeSetMuteRequestedEventArgs::GetDeferral()
{
    std::lock_guard<std::mutex> lockGuard(m_lock);
    if (m_raised)
    {
        // Cannot ask for a deferral after the event handler has returned.
        throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
    }

    m_completionsRequired++;
    auto handler = ref new DeferralCompletedHandler(this, &VolumeSetMuteRequestedEventArgs::Complete);
    return ref new Deferral(handler);
}

void VolumeSetMuteRequestedEventArgs::InvokeAllFinished()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        m_raised = true;
        invokeNeeded = (m_completionsRequired == 0);
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void VolumeSetMuteRequestedEventArgs::Complete()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        if (m_completionsRequired == 0)
        {
            // This should never happen since Complete() should only be called by Windows.Foundation.Deferral
            // which will only invoke our completion handler once.
            throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
        }
        m_completionsRequired--;
        invokeNeeded = (m_raised && (m_completionsRequired == 0));
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void VolumeSetMuteRequestedEventArgs::InvokeCompleteHandler()
{
    if (m_result->Status == ER_NOT_IMPLEMENTED)
    {
        throw Exception::CreateException(E_NOTIMPL, "No handlers are registered for SetMuteRequested.");
    }
    else
    {
        m_tce.set(m_result);
    }
}

VolumeSetVolumeRequestedEventArgs::VolumeSetVolumeRequestedEventArgs(
    _In_ AllJoynMessageInfo^ info,
    _In_ int16 value)
    : m_raised(false),
    m_completionsRequired(0),
    m_messageInfo(info),
    m_value(value)
{
	m_result = VolumeSetVolumeResult::CreateFailureResult(ER_NOT_IMPLEMENTED);
}

Deferral^ VolumeSetVolumeRequestedEventArgs::GetDeferral()
{
    std::lock_guard<std::mutex> lockGuard(m_lock);
    if (m_raised)
    {
        // Cannot ask for a deferral after the event handler has returned.
        throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
    }

    m_completionsRequired++;
    auto handler = ref new DeferralCompletedHandler(this, &VolumeSetVolumeRequestedEventArgs::Complete);
    return ref new Deferral(handler);
}

void VolumeSetVolumeRequestedEventArgs::InvokeAllFinished()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        m_raised = true;
        invokeNeeded = (m_completionsRequired == 0);
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void VolumeSetVolumeRequestedEventArgs::Complete()
{
    bool invokeNeeded;

    // We need to hold a lock while modifying private state, but release it before invoking a completion handler.
    {
        std::lock_guard<std::mutex> lockGuard(m_lock);
        if (m_completionsRequired == 0)
        {
            // This should never happen since Complete() should only be called by Windows.Foundation.Deferral
            // which will only invoke our completion handler once.
            throw Exception::CreateException(E_ILLEGAL_METHOD_CALL);
        }
        m_completionsRequired--;
        invokeNeeded = (m_raised && (m_completionsRequired == 0));
    }

    if (invokeNeeded)
    {
        InvokeCompleteHandler();
    }
}

void VolumeSetVolumeRequestedEventArgs::InvokeCompleteHandler()
{
    if (m_result->Status == ER_NOT_IMPLEMENTED)
    {
        throw Exception::CreateException(E_NOTIMPL, "No handlers are registered for SetVolumeRequested.");
    }
    else
    {
        m_tce.set(m_result);
    }
}

} } } } 