#pragma once
#include "ofMain.h"
#include "SafeDeque.h"
#include "MaskFrame.h"

class CanvasContents{
public:
    CanvasContents(){
        frameNudge = false;
    }
    void add(MaskFrame *maskFrame);
    void nudge(Direction direction);
    void eraseHighlighted();
    void eraseAll();
    
    void createMaskPointAt(int x, int y);
    void updateHighlights(int x, int y);
    void toggleFrameNudge();
    
    MaskFrame* beginTransform();
    void endTransform();
    void undo();
    void redo();
    bool getFrameNudgeEnabled();
    
    void drawDesign();
    void drawLive(DisplayMode displayMode, StretchMode stretchMode);
    
    SafeDeque<MaskFrame> *getMaskFrames();
    
protected:
    MaskFrame *lastHighlightedMaskFrame;
    SafeDeque<MaskFrame> maskFrames;
    bool frameNudge;
    
    void unhighlightAllMaskFrames();
    int getHighlightedMaskFrameIndex();
    MaskFrame* getHighlightedMaskFrame();
    bool hasHighlightedMaskFrame();
    void assignMaskFrameIds();
};
