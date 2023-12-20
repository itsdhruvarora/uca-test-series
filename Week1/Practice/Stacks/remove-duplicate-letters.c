char* removeDuplicateLetters(char* s) {
    int vis[26] = {0};
    int last[26] = {-1};

    for(int i=0; i<strlen(s); i++){
        last[s[i] - 'a'] = i;
    }

    char* ans = (char*)malloc((strlen(s) + 1) * sizeof(char));
    int p = 0;

    for(int i=0; i<strlen(s); i++){
        if(vis[s[i] - 'a']) continue;

        while(p != 0 && ans[p-1] > s[i] && last[ans[p-1] - 'a'] > i){
            vis[ans[--p] - 'a'] = 0;
        }

        ans[p++] = s[i];
        vis[s[i] - 'a'] = 1;
    }

    ans[p] = '\0';
    return ans;
}
