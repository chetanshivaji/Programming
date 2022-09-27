class Trie {
public:
    bool endWord;
    Trie*p[26];
    Trie() {
        endWord = false;
        for(int i=0;i<26;i++)
        {
            p[i]=NULL;
        }
    }
    
    void insert(string word)
    {
        Trie *temp = this;
        //search and found.
        for(auto c: word)
        {
            if(temp->p[c-'a']!=NULL)
            {
                temp=temp->p[c-'a'];
            }
            else
            {
                temp->p[c-'a'] = new Trie;
                temp=temp->p[c-'a'];
            }
        }
        temp->endWord = true;
        //search and not found create node assign.
    }
    
    bool search(string word) {
        Trie *temp = this;
        for(auto c:word)
        {
            if(temp->p[c-'a']!=NULL)
            {
                temp = temp->p[c-'a'];
            }
            else
            {
                return false;
            }
        }
        if(temp->endWord==true)
            return true;
        else
            return false;
    }
    
    bool startsWith(string prefix) 
    {
        Trie*temp=this;
        for(auto c:prefix)
        {
            if(temp->p[c-'a']!=NULL)
            {
                temp = temp->p[c-'a'];
            }
            else
                return false;
        }
        if(temp!=NULL)
            return true;
        else
            return false;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
