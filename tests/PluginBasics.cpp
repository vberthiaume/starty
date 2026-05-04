#include "helpers/test_helpers.h"
#include <dsp/PluginProcessor.h>
#include <ui/PluginEditor.h>
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

TEST_CASE ("Plugin editor", "[editor]")
{
    runWithinPluginEditor (
        [] (PluginProcessor& plugin)
        {
            auto* editor = plugin.getActiveEditor();
            REQUIRE (editor != nullptr);
            CHECK (editor->getWidth() == PluginEditor::width);
            CHECK (editor->getHeight() == PluginEditor::height);
            CHECK (editor->getNumChildComponents() > 0);
        });
}

TEST_CASE ("processBlock realtime", "[rtsan]")
{
    PluginProcessor plugin;
    constexpr auto  sampleRate { 44100.0 };
    constexpr auto  bufferSize { 512 };
    plugin.prepareToPlay (sampleRate, bufferSize);

    constexpr auto           numChannels { 2 };
    juce::AudioBuffer<float> buffer (numChannels, bufferSize);
    juce::MidiBuffer         midi;
    plugin.processBlock (buffer, midi);
}
