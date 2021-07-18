package Miscellaneous

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;

class concatenatedWordsTest {

    private final ConcatenatedWords ConcatenatedWords = new ConcatenatedWords();

    @Test
    void test1() {
        String[] words = {"tech", "lead", "techlead", "cat", "cats", "dog", "catsdog"};
        List<String> res = new ArrayList<>(Arrays.asList("techlead", "catsdog"));
        System.out.println(ConcatenatedWords.solve(words));
        assertEquals(res, ConcatenatedWords.solve(words));
    }

    @Test
    void test2() {
        String[] words = {"cat","dog","catdog"};
        List<String> res = new ArrayList<>(Collections.singletonList("catdog"));
        System.out.println(ConcatenatedWords.solve(words));
        assertEquals(res, ConcatenatedWords.solve(words));
    }

    @Test
    void test3() {
        String[] words = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
        List<String> res = new ArrayList<>(Arrays.asList("catsdogcats","dogcatsdog","ratcatdogcat"));
        System.out.println(ConcatenatedWords.solve(words));
        assertEquals(res, ConcatenatedWords.solve(words));
    }


}