class Solution {
    public boolean checkIfPangram(String sentence) {
		if (sentence.length() < 26) {
			return false;
		}
		String alphas = "abcdefghijklmnopqrstuvwxyz";
		for (int i = 0; i < alphas.length(); i++) {
			if (sentence.indexOf(alphas.charAt(i)) == -1) {
				return false;
			}
		}
		return true;
	}
}
