#include "PluginEditor.h"

PluginEditor::PluginEditor (PluginProcessor& p) : AudioProcessorEditor (&p), processorRef (p)
{
    juce::ignoreUnused (processorRef);

    addAndMakeVisible (inspectButton);

    // this chunk of code instantiates and opens the melatonin inspector
    inspectButton.onClick = [&]
    {
        if (! inspector)
        {
            inspector          = std::make_unique<melatonin::Inspector> (*this);
            inspector->onClose = [this]() { inspector.reset(); };
        }

        inspector->setVisible (true);
    };

    setSize (width, height);
}

void PluginEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    auto area = getLocalBounds();
    g.setColour (juce::Colours::white);
    g.setFont (fontSize);
    const auto helloWorld = juce::String() + PRODUCT_NAME_WITHOUT_VERSION + " v" VERSION + " in " + CMAKE_BUILD_TYPE;
    const auto textHeight { 150 };
    g.drawText (helloWorld, area.removeFromTop (textHeight), juce::Justification::centred, false);
}

void PluginEditor::resized()
{
    // layout the positions of your child components here
    auto       area = getLocalBounds();
    const auto buffer { 50 };
    area.removeFromBottom (buffer);
    const auto buttonW { 100 };
    const auto buttonH { 50 };
    inspectButton.setBounds (getLocalBounds().withSizeKeepingCentre (buttonW, buttonH));
}
