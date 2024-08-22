#include <stdio.h>
#include <string.h>
#define MAX_CANDIDATES 3
#define MAX_VOTERS 10
typedef struct {
    char voterID[20];
    int hasVoted;
} Voter;
typedef struct {
    char name[20];
    int votes;
} Candidate;
void registerVoter(Voter voters[], int *voterCount, const char *voterID) {
    strcpy(voters[*voterCount].voterID, voterID);
    voters[*voterCount].hasVoted = 0;
    (*voterCount)++;
}
int findVoterIndex(Voter voters[], int voterCount, const char *voterID) {
    for (int i = 0; i < voterCount; i++) {
        if (strcmp(voters[i].voterID, voterID) == 0) {
            return i;
        }
    }
    return -1;
}
void castVote(Voter voters[], int voterCount, Candidate candidates[], const char *voterID) {
    int voterIndex = findVoterIndex(voters, voterCount, voterID);
    if (voterIndex == -1) {
        printf("Invalid voter.\n");
        return;
    }
    if (voters[voterIndex].hasVoted) {
        printf("Voter has already voted.\n");
        return;
    }
    int candidateIndex;
    printf("Enter candidate number (1 for ABC, 2 for XYZ, 3 for PQR): ");
    scanf("%d", &candidateIndex);
    if (candidateIndex < 1 || candidateIndex > MAX_CANDIDATES) {
        printf("Invalid candidate.\n");
        return;
    }
    candidates[candidateIndex - 1].votes++;
    voters[voterIndex].hasVoted = 1;
    printf("Your vote has been cast successfully.\n");
}
void displayResults(Candidate candidates[]) {
    printf("\nElection Results:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}
int main() {
    Voter voters[MAX_VOTERS];
    Candidate candidates[MAX_CANDIDATES] = {{"ABC", 0}, {"XYZ", 0}, {"PQR", 0}};
    int voterCount = 0, n, i;
    char voterID[20];
    printf("Enter number of voters to register: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter Voter ID for Voter %d: ", i + 1);
        scanf("%s", voterID);
        registerVoter(voters, &voterCount, voterID);
    }
    printf("\nVoting process starts now:\n");
    for (i = 0; i < n; i++) {
        printf("Enter Voter ID: ");
        scanf("%s", voterID);
        castVote(voters, voterCount, candidates, voterID);
    }
    displayResults(candidates);

    return 0;
}
