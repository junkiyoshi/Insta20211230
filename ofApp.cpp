#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(255);
	ofSetColor(0);
	ofSetLineWidth(2.5);

	this->frame.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);

	this->frame.clear();

	float phi_deg_step = 3;
	float theta_deg_step = 3;

	float radius = 300;

	for (float phi_deg = 0; phi_deg < 360; phi_deg += phi_deg_step) {

		for (float theta_deg = 20; theta_deg <= 90; theta_deg += theta_deg_step) {

			auto noise_value = ofNoise(phi_deg * 0.85, theta_deg * 0.05 - ofGetFrameNum() * 0.05);

			if (noise_value < 0.5) {

				this->frame.addVertex(glm::vec3(
					radius * sin((theta_deg - theta_deg_step * 0.5) * DEG_TO_RAD) * cos((phi_deg + phi_deg_step * 0.5) * DEG_TO_RAD),
					radius * sin((theta_deg - theta_deg_step * 0.5) * DEG_TO_RAD) * sin((phi_deg + phi_deg_step * 0.5) * DEG_TO_RAD),
					0));
				this->frame.addVertex(glm::vec3(
					radius * sin((theta_deg + theta_deg_step * 0.5) * DEG_TO_RAD) * cos((phi_deg - phi_deg_step * 0.5) * DEG_TO_RAD),
					radius * sin((theta_deg + theta_deg_step * 0.5) * DEG_TO_RAD) * sin((phi_deg - phi_deg_step * 0.5) * DEG_TO_RAD),
					0));
			}
			else {

				this->frame.addVertex(glm::vec3(
					radius * sin((theta_deg - theta_deg_step * 0.5) * DEG_TO_RAD) * cos((phi_deg - phi_deg_step * 0.5) * DEG_TO_RAD),
					radius * sin((theta_deg - theta_deg_step * 0.5) * DEG_TO_RAD) * sin((phi_deg - phi_deg_step * 0.5) * DEG_TO_RAD),
					0));
				this->frame.addVertex(glm::vec3(
					radius * sin((theta_deg + theta_deg_step * 0.5) * DEG_TO_RAD) * cos((phi_deg + phi_deg_step * 0.5) * DEG_TO_RAD),
					radius * sin((theta_deg + theta_deg_step * 0.5) * DEG_TO_RAD) * sin((phi_deg + phi_deg_step * 0.5) * DEG_TO_RAD),
					0));
			}

			this->frame.addIndex(this->frame.getNumVertices() - 1);
			this->frame.addIndex(this->frame.getNumVertices() - 2);
		}
	}

	for (float phi_deg = 0; phi_deg < 360; phi_deg += phi_deg_step) {

		float theta_deg = 20;

		this->frame.addVertex(glm::vec3(
			radius * sin((theta_deg - theta_deg_step * 0.5) * DEG_TO_RAD) * cos((phi_deg + phi_deg_step * 0.5) * DEG_TO_RAD),
			radius * sin((theta_deg - theta_deg_step * 0.5) * DEG_TO_RAD) * sin((phi_deg + phi_deg_step * 0.5) * DEG_TO_RAD),
			0));
		this->frame.addVertex(glm::vec3(
			radius * sin((theta_deg - theta_deg_step * 0.5) * DEG_TO_RAD) * cos((phi_deg - phi_deg_step * 0.5) * DEG_TO_RAD),
			radius * sin((theta_deg - theta_deg_step * 0.5) * DEG_TO_RAD) * sin((phi_deg - phi_deg_step * 0.5) * DEG_TO_RAD),
			0));
		this->frame.addIndex(this->frame.getNumVertices() - 1);
		this->frame.addIndex(this->frame.getNumVertices() - 2);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	this->frame.draw();

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}