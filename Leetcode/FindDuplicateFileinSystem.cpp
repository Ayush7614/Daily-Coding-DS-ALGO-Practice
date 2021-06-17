/* 609. Find Duplicate File in System
MEDIUM

===================================================

Problem statement

Given a list paths of directory info, including the directory path, and all the files with contents in this directory, return all the duplicate files in the file system in terms of their paths. You may return the answer in any order.
A group of duplicate files consists of at least two files that have the same content.
A single directory info string in the input list has the following format:
"root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"
It means there are n files (f1.txt, f2.txt ... fn.txt) with content (f1_content, f2_content ... fn_content) respectively in the directory "root/d1/d2/.../dm". Note that n >= 1 and m >= 0. If m = 0, it means the directory is just the root directory.
The output is a list of groups of duplicate file paths. For each group, it contains all the file paths of the files that have the same content. A file path is a string that has the following format:
    "directory_path/file_name.txt"

Input: paths = ["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"]
Output: [["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]

========================================================

Solution*/

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
      unordered_map<string, vector<string>> Files;
	vector<vector<string> > ans;
	for(auto& path : paths) {
		int i = 0, j;
		while(path[i] != ' ') i++;   
		string dir = path.substr(0, i), file, content;
		while(i++ < size(path)) {
			j = i;
			while(path[i] != '(') i++;  
			file = path.substr(j, i - j);
			j = i;
			while(path[i++] != ')');    
			content = path.substr(j, i - j);
			Files[content].emplace_back(dir + '/' + file);
		}
	}
	for(auto& content : Files) 
		if(size(content.second) > 1)
			ans.push_back(move(content.second));
	return ans;
    }
};

