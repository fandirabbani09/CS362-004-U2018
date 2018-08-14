import java.security.SecureRandom;
import java.util.Base64;
import java.util.Base64.Encoder;

public class FinalProjectPartB {

    // uses command line input for manual testing
    public static void manualTesting(String[] args)
    {
        UrlValidator validator = new UrlValidator();
        System.out.println(args[0] + " valid?: " + validator.isValid(args[0]));
    }

    // unit tests for valid url input based on the correct version
    public static void unitTestsForValidUrls()
    {
        // instantiate incorrect validator object
        UrlValidator validator = new UrlValidator();

        // create array of valid urls
        String[] testValidUrls = {
            "https://www.google.com",
            "http://www.google.com",
            "http://123.google.com",
            "https://192.168.1.1",
            "https://www.com",
            "https://http.com",
            "https://www.1.com",
            "https://1.com",
            "https://1.ly",
            "https://1.xxx",
            "https://oregonstate.instructure.com/courses/1683590/assignments/7302434#submit",
            "http://www.cplusplus.com/files/tutorial.pdf",
            "http://www.1.ba",
            "http://www.1.bb",
            "http://www.1.army",
            "http://www.1.adult",
            "http://www.1.wien",
            "http://www.1.wtf",
            "http://www.1.yokohama",
            "http://www.1.wedding",
            "http://www.thelongestdomainnameintheworldandthensomeandthensomemoreandmore.com/",
            "http://iamtheproudownerofthelongestlongestlongestdomainnameinthisworld.com/",
            "https://www.blah.com"
        };

        // assert valid urls
        for (int i = 0; i < testValidUrls.length; i++)
        {
            assert(validator.isValid(testValidUrls[i]) == true);
        }

        System.out.println("Passed all valid URL test.");
    }

    // unit tests for invalid url input based on the correct version
    public static void unitTestsForInvalidUrls()
    {
        // instantiate incorrect validator object
        UrlValidator validator = new UrlValidator();
        
        // create array of invalid urls
        String[] testInvalidUrls = {
            "//http://iamtheproudownerofthelongestlongestlongestdomainnameinthisworld.com/",
            "https://1",
            "https://1.1",
            "http://www.1.a",
            "http://www.1.b",
            "http://www.1.bc",
            "httpss://www.google.com",
            "https:///www.google.com",
            "https://www..com",
            "https://www./.com"
        };

        // assert invalid urls
        for (int i = 0; i < testInvalidUrls.length; i++)
        {
            assert(validator.isValid(testInvalidUrls[i]) == false);
        }

        System.out.println("Passed all invalid URL test.");
    }

    // main method, runs the unit tests
    public static void main(String[] args)
    {
        manualTesting(args);
        unitTestsForValidUrls();
        unitTestsForInvalidUrls();
    }
}