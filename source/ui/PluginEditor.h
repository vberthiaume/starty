#pragma once

#include "../dsp/PluginProcessor.h"
#include "BinaryData.h"
#include "melatonin_inspector/melatonin_inspector.h"

// NOLINTNEXTLINE(cppcoreguidelines-special-member-functions)
class PluginEditor : public juce::AudioProcessorEditor
{
public:
    static constexpr auto width { 400 };
    static constexpr auto height { 300 };
    static constexpr auto fontSize { 16.f };

    explicit PluginEditor (PluginProcessor&);
    ~PluginEditor() override = default;

    void paint (juce::Graphics& g) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to access the processor object that created it.
    PluginProcessor&                      processorRef;
    std::unique_ptr<melatonin::Inspector> inspector;
    juce::TextButton                      inspectButton { "Inspect the UI" };
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};
