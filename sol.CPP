#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

class Candidate {
private:
    string name;
    int votes;

public:
    Candidate() : name(""), votes(0) {}

    Candidate(const string& name) : name(name), votes(0) {}

    void addVote() {
        votes++;
    }

    const string& getName() const {
        return name;
    }

    int getVotes() const {
        return votes;
    }
};

class Voter {
private:
    string voterID;
    bool hasVoted;

public:
    Voter() : voterID(""), hasVoted(false) {}

    Voter(const string& id) : voterID(id), hasVoted(false) {}

    const string& getVoterID() const {
        return voterID;
    }

    bool hasVotedInElection() const {
        return hasVoted;
    }

    void vote() {
        hasVoted = true;
    }
};


class Election {
private:
    string name;
    map<string, Candidate> candidates;
    map<string, Voter> voters;

public:
    Election(const string& name) : name(name) {}

    void addCandidate(const string& name) {
        candidates.emplace(name, Candidate(name));
    }

    void addVoter(const string& id) {
        voters.emplace(id, Voter(id));
    }

    void vote(const string& voterID, const string& candidateName) {
        auto voterIt = voters.find(voterID);
        if (voterIt == voters.end()) {
            throw runtime_error("Voter not registered.");
        }
        if (voterIt->second.hasVotedInElection()) {
            throw runtime_error("This voter has already voted.");
        }

        auto candidateIt = candidates.find(candidateName);
        if (candidateIt == candidates.end()) {
            throw runtime_error("Candidate not found.");
        }

        candidateIt->second.addVote();
        voterIt->second.vote();
    }

    void displayResults() const {
        cout << "===============================================================================================================================================\n";
        cout << "                                                        -> Election Results for " << name << " <-\n";
        cout << "===============================================================================================================================================\n";
        vector<pair<int, string>> result;
        for (const auto& candidate : candidates) {
            result.push_back( make_pair( candidate.second.getVotes() , candidate.second.getName()));
        }
        sort(result.rbegin( ) , result.rend());
        string winner=result[0].second;
        cout<<"                                                               ";
        string a="The Winner is:\n";
        for(int i=0;i<a.length();i++){
            Sleep(20);
            cout<<a[i];
        }
        cout<<"                                                                    ";
        string b="3...";
        for(int i=0;i<b.length();i++){
            Sleep(300);
            cout<<b[i];
        }
        cout<<"\n";
        cout<<"                                                                    ";
        b="2...";
        for(int i=0;i<b.length();i++){
            Sleep(300);
            cout<<b[i];
        }
        cout<<"\n";
        cout<<"                                                                    ";
        b="1...";
        for(int i=0;i<b.length();i++){
            Sleep(300);
            cout<<b[i];
        }
        int p=33-winner.size();
        p/=2;
        cout<<"\n";
        cout << "                                                    _____                                   _____ \n";
        cout << "                                                   ( ___ )---------------------------------( ___ )\n";
        cout << "                                                    |   |                                   |   | \n";
        cout << "                                                    |   |                                   |   | \n";
        cout << "                                                    |   | ";
        for(int i=0;i<p;i++)
        cout << " ";
        for(int i=0;i<winner.length();i++){
            Sleep(100);
            cout<<winner[i];
        }
        for(int i=0;i<p;i++)
        cout << " ";
        cout << " |   | \n";
        cout << "                                                    |   |                                   |   | \n";
        cout << "                                                    |___|                                   |___| \n";
        cout << "                                                   (_____)---------------------------------(_____)\n";

        cout<<"\n";
        cout << "===============================================================================================================================================\n";
        for (const auto& candidate : candidates) {
            cout << candidate.second.getName() << ": " << candidate.second.getVotes() << " votes\n";
        }
        cout << "===============================================================================================================================================\n";
    }

    void saveData() const {
        ofstream outFile(name + "_results.txt");
        if (outFile.is_open()) {
            for (const auto& candidate : candidates) {
                outFile << candidate.second.getName() << " " << candidate.second.getVotes() << "\n";
            }
            string b= "===============================================================================================================================================\n\n";
            for(int i=0;i<b.length();i++){
                Sleep(0);
                cout<<b[i];
            }
            cout << "                                                              "; 
            string a="         ##         \n";
            for(int i=0;i<a.length();i++){
                Sleep(10);
                cout<<a[i];
            }
            cout << "                                                              ";        
            a="       ######       \n";
            for(int i=0;i<a.length();i++){
                Sleep(10);
                cout<<a[i];
            }
            cout << "                                                              ";        
            a="     ##########     \n";
            for(int i=0;i<a.length();i++){
                Sleep(10);
                cout<<a[i];
            }
            cout << "                                                              ";        
            a="     ##########     \n";
            for(int i=0;i<a.length();i++){
                Sleep(10);
                cout<<a[i];
            }
            cout << "                                                              ";        
            a="        ####        \n";
            for(int i=0;i<a.length();i++){
                Sleep(10);
                cout<<a[i];
            }
            cout << "                                                              ";        
            a="###     ####     ###\n";
            for(int i=0;i<a.length();i++){
                Sleep(10);
                cout<<a[i];
            }
            cout << "                                                              ";        
            a="###     ####     ###\n";
            for(int i=0;i<a.length();i++){
                Sleep(10);
                cout<<a[i];
            }
            cout << "                                                              ";        
            a="###     ####     ###\n";
            for(int i=0;i<a.length();i++){
                Sleep(10);
                cout<<a[i];
            }
            cout << "                                                              ";        
            a="###              ###\n";
            for(int i=0;i<a.length();i++){
                Sleep(10);
                cout<<a[i];
            }
            cout << "                                                              ";        
            a="####################\n";
            for(int i=0;i<a.length();i++){
                Sleep(10);
                cout<<a[i];
            }
            outFile.close();
            cout << "\n\n";
            cout << "                                                     Results saved to " << name << "_results.txt\n\n";

        } else {
            throw runtime_error("Unable to save results.");
        }

        ofstream voterFile(name + "_voters.txt");
        if (voterFile.is_open()) {
            for (const auto& voter : voters) {
                voterFile << voter.second.getVoterID() << " " << voter.second.hasVotedInElection() << "\n";
            }
            voterFile.close();
            cout << "                                               Voter information saved to " << name << "_voters.txt\n";
        } else {
            throw runtime_error("Unable to save voter information.");
        }
    }

    void loadData() {
        ifstream inFile(name + "_results.txt");
        if (inFile.is_open()) {
            string candidateName;
            int voteCount;
            while (inFile >> candidateName >> voteCount) {
                candidates[candidateName] = Candidate(candidateName);
                for (int i = 0; i < voteCount; ++i) {
                    candidates[candidateName].addVote();
                }
            }
            cout << "===============================================================================================================================================\n\n";
            cout << "                                                              ";
            string a="        ####        \n";
            for(int i=0;i<a.length();i++){
                Sleep(10);
                cout<<a[i];
            }
            cout << "                                                              ";        
            a="        ####        \n";
            for(int i=0;i<a.length();i++){
                Sleep(10);
                cout<<a[i];
            }
            cout << "                                                              ";        
            a="        ####        \n";
            for(int i=0;i<a.length();i++){
                Sleep(10);
                cout<<a[i];
            }
            cout << "                                                              ";        
            a="     ##########     \n";
            for(int i=0;i<a.length();i++){
                Sleep(10);
                cout<<a[i];
            }
            cout << "                                                              ";        
            a="###  ##########  ###\n";
            for(int i=0;i<a.length();i++){
                Sleep(10);
                cout<<a[i];
            }
            cout << "                                                              ";        
            a="###    ######    ###\n";
            for(int i=0;i<a.length();i++){
                Sleep(10);
                cout<<a[i];
            }
            cout << "                                                              ";        
            a="###     ####     ###\n";
            for(int i=0;i<a.length();i++){
                Sleep(10);
                cout<<a[i];
            }
            cout << "                                                              ";        
            a="###      ##      ###\n";
            for(int i=0;i<a.length();i++){
                Sleep(10);
                cout<<a[i];
            }
            cout << "                                                              ";        
            a="####################\n";
            for(int i=0;i<a.length();i++){
                Sleep(10);
                cout<<a[i];
            }
            cout << "                                                              ";        
            a="####################\n";
            for(int i=0;i<a.length();i++){
                Sleep(10);
                cout<<a[i];
            }
            inFile.close();
            cout << "\n\n";
            cout << "                                                     Results loaded from " << name << "_results.txt\n\n";
        } else {
            throw runtime_error("Unable to load results.");
        }

        ifstream voterFile(name + "_voters.txt");
        if (voterFile.is_open()) {
            string voterID;
            bool hasVoted;
            while (voterFile >> voterID >> hasVoted) {
                voters[voterID] = Voter(voterID);
                if (hasVoted) {
                    voters[voterID].vote();
                }
            }
            voterFile.close();
            cout << "\n";
            cout << "                                               Voter information loaded from " << name << "_voters.txt\n";
        } else {
            throw runtime_error("Unable to load voter information.");
        }
    }
};

class VotingSystem {
private:
    map<string, Election> elections;

public:
    void createElection(const string& name) {
        elections.emplace(name, Election(name));
    }

    void addCandidateToElection(const string& electionName, const string& candidateName) {
        auto it = elections.find(electionName);
        if (it != elections.end()) {
            it->second.addCandidate(candidateName);
        } else {
            throw runtime_error("Election not found.");
        }
    }

    void registerVoter(const string& electionName, const string& voterID) {
        auto it = elections.find(electionName);
        if (it != elections.end()) {
            it->second.addVoter(voterID);
        } else {
            throw runtime_error("Election not found.");
        }
    }

    void voteInElection(const string& electionName, const string& voterID, const string& candidateName) {
        auto it = elections.find(electionName);
        if (it != elections.end()) {
            it->second.vote(voterID, candidateName);
        } else {
            throw runtime_error("Election not found.");
        }
    }

    void displayResults(const string& electionName) const {
        auto it = elections.find(electionName);
        if (it != elections.end()) {
            it->second.displayResults();
        } else {
            throw runtime_error("Election not found.");
        }
    }

    void saveResults(const string& electionName) const {
        auto it = elections.find(electionName);
        if (it != elections.end()) {
            it->second.saveData();
        } else {
            throw runtime_error("Election not found.");
        }
    }

    void loadResults(const string& electionName) {
        auto it = elections.find(electionName);
        if (it == elections.end()) {
            elections.emplace(electionName, Election(electionName));
            it = elections.find(electionName);
        }
        it->second.loadData();
    }
};

class VotingApp {
private:
    VotingSystem votingSystem;

public:
    void thankyou(){
        cout << "                                              //////////////////////////////////////////////////////////////////\n";
        cout << "                                              //                                                              //\n";
        cout << "                                              //    _____ _                 _                        _ _ _    //\n";
        cout << "                                              //   |_   _| |__   __ _ _ __ | | ___   _  ___  _   _  | | | |   //\n";
        cout << "                                              //     | | | '_ \\ / _` | '_ \\| |/ / | | |/ _ \\| | | | | | | |   //\n";
        cout << "                                              //     | | | | | | (_| | | | |   <| |_| | (_) | |_| | |_|_|_|   //\n";
        cout << "                                              //     |_| |_| |_|\\__,_|_| |_|_|\\_\\__, |\\___/ \\__,_| (_|_|_)    //\n";
        cout << "                                              //                                 |___/                        //\n";
        cout << "                                              //                                                              //\n";
        cout << "                                              //////////////////////////////////////////////////////////////////\n";
    }
    void run() {
        int choice,flag=0;
        do {
            string a="\n=================================================================== ";
            string b="Voting System";
            string c=" ===================================================================\n";
            for(int i=0;i<a.length();i++){
                Sleep(flag==0?1:0);
                cout<<a[i];
            }
            for(int i=0;i<b.length();i++){
                Sleep(flag==0?50:10);
                cout<<b[i];
            }
            for(int i=0;i<c.length();i++){
                Sleep(flag==0?1:0);
                cout<<c[i];
            }
            Sleep(flag==0?200:100);
            cout << "=                                                               1. Create Election                                                                  =\n";
            Sleep(flag==0?200:100);
            cout << "=                                                               2. Add Candidate                                                                    =\n";
            Sleep(flag==0?200:100);
            cout << "=                                                               3. Register Voter                                                                   =\n";
            Sleep(flag==0?200:100);
            cout << "=                                                               4. Vote                                                                             =\n";
            Sleep(flag==0?200:100);
            cout << "=                                                               5. Display Results                                                                  =\n";
            Sleep(flag==0?200:100);
            cout << "=                                                               6. Save Data                                                                        =\n";
            Sleep(flag==0?200:100);
            cout << "=                                                               7. Load Data                                                                        =\n";
            Sleep(flag==0?200:100);
            cout << "=                                                               8. Exit                                                                             =\n";
            Sleep(flag==0?200:100);
            cout << "=                                                               Enter your choice (1-8):                                                            =\n";
            Sleep(flag==0?200:100);
            cout << "                                                                ";
            cin >> choice;
            cout << "\n";
            switch (choice) {
                case 1: {
                    string electionName;
                    cout << "                                                                ";
                    string election1="Enter election name:\n";
                    for(int i=0;i<election1.length();i++){
                        Sleep(20);
                        cout<<election1[i];
                    }
                    cout << "                                                                ";
                    cin.ignore();
                    getline(cin, electionName);
                    votingSystem.createElection(electionName);
                    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------\n";
                    cout << "||                                                                                                                                                 ||\n";
                    cout << "                                                       Election " << electionName << " created successfully.\n";
                    cout << "||                                                                                                                                                 ||\n";
                    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------\n";
                    break;
                }
                case 2: {
                    string electionName, candidateName;
                    cout << "\n";
                    cout << "                                                                ";
                    string election1="Enter election name:\n";
                    for(int i=0;i<election1.length();i++){
                        Sleep(20);
                        cout<<election1[i];
                    }
                    cout << "                                                                ";
                    cin.ignore();
                    getline(cin, electionName);
                    cout << "\n";
                    cout << "                                                                ";
                    election1="Enter candidate name:\n";
                    for(int i=0;i<election1.length();i++){
                        Sleep(20);
                        cout<<election1[i];
                    }
                    cout << "                                                                ";
                    getline(cin, candidateName);
                    cout << "\n";
                    cout << "=====================================================================================================================================================\n";
                    cout << "\n";
                    try {
                        votingSystem.addCandidateToElection(electionName, candidateName);
                        cout << "                                                        Candidate " << candidateName << " added successfully to " << electionName << ".\n";
                    } catch (runtime_error& e) {
                        cout << "                                                        Error: " << e.what() << '\n';
                    }
                    break;
                }
                case 3: {
                    string electionName, voterID;
                    cout << "                                                                ";
                    string election1="Enter election name:\n";
                    for(int i=0;i<election1.length();i++){
                        Sleep(20);
                        cout<<election1[i];
                    }
                    cout << "                                                                ";
                    cin.ignore();
                    getline(cin, electionName);
                    cout << "                                                                ";
                    election1="Enter Voted ID:\n";
                    for(int i=0;i<election1.length();i++){
                        Sleep(20);
                        cout<<election1[i];
                    }
                    cout << "                                                                ";
                    getline(cin, voterID);
                    cout << "=====================================================================================================================================================\n";
                    cout << "\n";
                    try {
                        votingSystem.registerVoter(electionName, voterID);
                        cout << "                                                        Voter " << voterID << " registered successfully for " << electionName << ".\n";
                    } catch (runtime_error& e) {
                        cout << "                                                        Error: " << e.what() << '\n';
                    }
                    break;
                }
                case 4: {
                    string electionName, voterID, candidateName;
                    cout << "                                                                ";
                    string election1="Enter election name:\n";
                    for(int i=0;i<election1.length();i++){
                        Sleep(20);
                        cout<<election1[i];
                    }
                    cout << "                                                                ";
                    cin.ignore();
                    getline(cin, electionName);
                    cout << "                                                                ";
                    election1="Enter Voted ID:\n";
                    for(int i=0;i<election1.length();i++){
                        Sleep(20);
                        cout<<election1[i];
                    }
                    cout << "                                                                ";
                    getline(cin, voterID);
                    cout << "                                                                ";
                    election1="Enter candidate name:\n";
                    for(int i=0;i<election1.length();i++){
                        Sleep(20);
                        cout<<election1[i];
                    }
                    cout << "                                                                ";
                    getline(cin, candidateName);
                    cout << "=====================================================================================================================================================\n";
                    try {
                        votingSystem.voteInElection(electionName, voterID, candidateName);
                        cout << "                                                   Vote for " << candidateName << " cast successfully in " << electionName << ".\n";
                    } catch (runtime_error& e) {
                        cout << "\n";
                        cout << "                                                       Error: " << e.what() << '\n';
                    }
                    break;
                }
                case 5: {
                    string electionName;
                    cout << "                                                                ";
                    string election1="Enter election name:\n";
                    for(int i=0;i<election1.length();i++){
                        Sleep(20);
                        cout<<election1[i];
                    }
                    cout << "                                                                ";
                    cin.ignore();
                    getline(cin, electionName);
                    try {
                        votingSystem.displayResults(electionName);
                    } catch (runtime_error& e) {
                        cout << "                                                        Error: " << e.what() << '\n';
                    }
                    break;
                }
                case 6: {
                    string electionName;
                    cout << "                                                                ";
                    string election1="Enter election name:\n";
                    for(int i=0;i<election1.length();i++){
                        Sleep(20);
                        cout<<election1[i];
                    }
                    cout << "                                                                ";
                    cin.ignore();
                    getline(cin, electionName);
                    try {
                        votingSystem.saveResults(electionName);
                    } catch (runtime_error& e) {
                        cout << "                                                        Error: " << e.what() << '\n';
                    }
                    break;
                }
                case 7: {
                    string electionName;
                    cout << "                                                                ";
                    string election1="Enter election name:\n";
                    for(int i=0;i<election1.length();i++){
                        Sleep(20);
                        cout<<election1[i];
                    }
                    cout << "                                                                ";
                    cin.ignore();
                    getline(cin, electionName);
                    try {
                        votingSystem.loadResults(electionName);
                    } catch (runtime_error& e) {
                        cout << "                                                        Error: " << e.what() << '\n';
                    }
                    break;
                }
                case 8:
                    cout << "                                                            Exiting the Voting System.\n";
                    cout << "\n";
                    thankyou();
                    break;
                default:
                    cout << "                                             Invalid choice, please select a number between 1 and 8.\n";
            }
            flag=1;
        } while (choice != 8);
    }
};

int main() {
    VotingApp app;
    app.run();
    return 0;
}