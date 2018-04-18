#pragma once

#include "ofMain.h"
#include  "ofxAssimpModelLoader.h"
#include "box.h"
#include "ray.h"
#include <vector>

class TreeNode {

 public:
	Box box;
	vector<int> points;
	vector<TreeNode> children;

 public:
	TreeNode(){}
	void setBox(Box& inBox){
		this->box = inBox;
	}

	void setPoints(vector<int>& points){
		for(int i=0; i< points.size(); ++i){
			this->points.push_back(points[i]);
		}
	}

	bool setChild(TreeNode node){
		int oldLen = this->children.size();
		this->children.push_back(node);
		int newLen = this->children.size();
		return newLen > oldLen;
	}
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void drawAxis(ofVec3f);
		void initLightingAndMaterials();
		void savePicture();
		void toggleWireframeMode();
		void togglePointsDisplay();
		void toggleSelectTerrain();
		void setCameraTarget();
		bool  doPointSelection();
		void drawBox(const Box &box);
		Box meshBounds(const ofMesh &);
		void subDivideBox8(const Box &b, vector<Box> & boxList);
		void subDivideBox8_2();

		bool mouseIntersectPlane(ofVec3f planePoint, ofVec3f planeNorm, ofVec3f &point);

		ofEasyCam cam;
		ofxAssimpModelLoader mars, rover;
		ofLight light;
		Box boundingBox;
		vector<Box> level1, level2, level3, level4, level5;
	
		bool bAltKeyDown;
		bool bCtrlKeyDown;
		bool bWireframe;
		bool bDisplayPoints;
		bool bPointSelected;
		
		bool bRoverLoaded;
		bool bTerrainSelected;
	
		ofVec3f selectedPoint;
		ofVec3f intersectPoint;
		const float selectionRange = 4.0;

		void getMeshPointsInBox(const ofMesh &mesh, const vector<int>& points, Box & box, vector<int>& pointsRtn);

        void createOctree(const ofMesh& mesh, TreeNode& root, int lvl);
        void subdivide(const ofMesh& mesh, TreeNode& node, int lvl);


};


