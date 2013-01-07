
#include "G4UserRunAction.hh"
#include "globals.hh"

#include <iostream>
#include <fstream>

using namespace std;

class G4Run;

class RunAction : public G4UserRunAction
{
	public:
		RunAction();
		~RunAction();
		void BeginOfRunAction(const G4Run* aRun);
		void EndOfRunAction(const G4Run* aRun);
		
		void WriteToFile(G4double val, G4int scintNum);
		static RunAction* GetInstance();
		ofstream outfile;
		
	protected:

		
	private:

};