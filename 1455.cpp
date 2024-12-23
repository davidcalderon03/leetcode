class Solution {
public:
  int isPrefixOfWord(string sentence, string searchWord) {
    int count = 1;
    for (int i = 0; i < sentence.size(); ++i) {
      if (i == 0 || sentence[i - 1] == ' ') {
        bool match = true;
        for (int j = i; j < i + searchWord.size(); ++j) {
          std::cout << "Current letter: " << searchWord[j - i] << std::endl;
          if (searchWord[j - i] != sentence[j]) {
            match = false;
            break;
          }
        }
        if (match) {
          return count;
        }
        count++;
      }
    }
    return -1;
  }
};
