#include "helpers/test_helpers.h"
#include <dsp/PluginProcessor.h>
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

TEST_CASE ("Plugin instance", "[instance]")
{
    PluginProcessor testPlugin;

    // clang-format off
    SECTION ("name")
    {
        CHECK_THAT (testPlugin.getName().toStdString(), Catch::Matchers::Equals ("Starty"));
    }
    // clang-format on
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
