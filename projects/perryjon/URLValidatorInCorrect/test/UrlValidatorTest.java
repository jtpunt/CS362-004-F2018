
package partB;
import junit.framework.TestCase;
import java.util.Random;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!

public class UrlValidatorTest extends TestCase {
	
	ResultPair[] testUrlScheme = {
			new ResultPair("http://", true),
            new ResultPair("ftp://", true),
            new ResultPair("h3t://", true),
            new ResultPair("3ht://", false),
            new ResultPair("http:/", false),
            new ResultPair("http:", false),
            new ResultPair("http/", false),
            new ResultPair("://", false),
            new ResultPair("", true)
            
	};
	ResultPair[] testUrlAuthority = {
			new ResultPair("www.google.com", true),
            new ResultPair("go.com", true),
            new ResultPair("go.au", true),
            new ResultPair("0.0.0.0", true),
            new ResultPair("255.255.255.255", true),
            new ResultPair("256.256.256.256", false),
            new ResultPair("255.com", true),
            new ResultPair("1.2.3.4.5", false),
            new ResultPair("1.2.3.4.", false),
            new ResultPair("1.2.3", false),
            new ResultPair(".1.2.3.4", false),
            new ResultPair("go.a", false),
            new ResultPair("go.a1a", false),
            new ResultPair("go.1aa", false),
            new ResultPair("aaa.", false),
            new ResultPair(".aaa", false),
            new ResultPair("aaa", false),
            new ResultPair("", false)
	};
	ResultPair[] testUrlPort = {
			new ResultPair(":80", true),
            new ResultPair(":65535", true),
            new ResultPair(":0", true),
            new ResultPair("", true),
            new ResultPair(":-1", false),
            new ResultPair(":65636",false),
            new ResultPair(":65a", false)
	};
	ResultPair[] testPath = {new ResultPair("/test1", true),
            new ResultPair("/t123", true),
            new ResultPair("/$23", true),
            new ResultPair("/..", false),
            new ResultPair("/../", false),
            new ResultPair("/test1/", true),
            new ResultPair("", true),
            new ResultPair("/test1/file", true),
            new ResultPair("/..//file", false),
            new ResultPair("/test1//file", false)
	};
	ResultPair[] testUrlQuery = {
			new ResultPair("?action=view", true),
            new ResultPair("?action=edit&mode=up", true),
            new ResultPair("", true)
	};

	public UrlValidatorTest(String testName) {
		super(testName);
	}

	public void testManualTest() {
		//You can use this function to implement your manual testing
		// Set up valid schemes to test
		String[] schemes = { "http", "https" };
		UrlValidator urlValidator1 = new 
		UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES); // All
		UrlValidator urlValidator2 = new UrlValidator(schemes); // Only http and https schemes allowed
		UrlValidator urlValidator3 = new UrlValidator(null); // Default
		//-------------------urlValidator1 Testing-------------------//
		assertTrue(urlValidator1.isValid("https://www.google.com"));
		// Returns false, should return true
		assertTrue(urlValidator1.isValid("ftp://www.amazon.com"));
		// Returns false, should return true
		assertTrue(urlValidator1.isValid("https://www.amazon.com"));
		// Returns false, should return true
		assertFalse(urlValidator1.isValid("http://www.am@zon.com")); 
		// Returns true, should return false, '@' not a valid character
		//-------------------urlValidator2 Testing-------------------//
		assertTrue(urlValidator2.isValid("http://www.google.com")); 
		// Returns false, should return true, http a valid scheme
		assertTrue(urlValidator2.isValid("https://www.google.com")); 
		// Returns false, should return true, https a valid scheme
		assertFalse(urlValidator2.isValid("ftp://foo.bar.com/")); 
		// Returns true, should return false, only http and https valid schemes
		//-------------------urlValidator3 Testing-------------------//
		assertTrue(urlValidator3.isValid("https://foo.bar.com/"));
		// Default validator, should return true
		assertTrue(urlValidator3.isValid("ftp://foo.bar.com/")); 
		// Returns false, should return true
	}
   //Partition for Port #'s - less than 0, 0 - 65535, < 65535
   public void testPortsPartition()
   {
	   //Setup testing variables
	   String schemeAuthority = "http://www.google.com";    //We know this is a valid scheme/authority
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   StringBuilder testBuffer = new StringBuilder();
	   String url;
	   boolean expected = true;
	   boolean result = true;
	   
	   //Ports to check
	   ResultPair[] testPorts = {new ResultPair(":-1", false),
			   new ResultPair(":0", true),
			   new ResultPair(":65535", true),
			   new ResultPair(":65636", false)};
	   
	   //Build test URL's using known valid scheme/authority combo + test port inputs
	   for(int i = 0; i < testPorts.length; ++i) {
		   // build test URL
		   testBuffer.append(schemeAuthority);
		   testBuffer.append(testPorts[i].item);
		   expected = testPorts[i].valid;
		   url = testBuffer.toString();
		   result = urlVal.isValid(url);
		   assertEquals(url, expected, result);
		   if(expected == result) {
			   System.out.printf("isValid() PASSED: %s - Expected: %s, Result: %s\n", url, expected, result);
		   } else {
			   System.out.printf("isValid() FAILED: %s - Expected: %s, Result: %s\n", url, expected, result);
		   }
		   testBuffer = new StringBuilder();
	   }
   }
	   
   public void testSchemePartition(){
	   
	   //Setup testing variables
	   String authority = "www.google.com";    // We know this is a valid authority
	   UrlValidator urlVal = new UrlValidator();    // initializes validator with default schemes - http, https and ftp
	   StringBuilder testBuffer = new StringBuilder();
	   String url;
	   boolean expected = true;
	   boolean result = true;
	   
	   // Schemes to check
	   ResultPair[] testSchemes = {new ResultPair("http", false),
			   new ResultPair("http:/", true),
			   new ResultPair("http://", true)};
	   
	   //Build test URL's using test schemes + known valid authority
	   for(int i = 0; i < testSchemes.length; ++i) {
		   // build test URL
		   testBuffer.append(testSchemes[i].item);
		   testBuffer.append(authority);
		   expected = testSchemes[i].valid;
		   url = testBuffer.toString();
		   result = urlVal.isValid(url);
		   assertEquals(url, expected, result);
		   if(expected == result) {
			   System.out.printf("isValid() PASSED: %s - Expected: %s, Result: %s\n", url, expected, result);
		   } else {
			   System.out.printf("isValid() FAILED: %s - Expected: %s, Result: %s\n", url, expected, result);
		   }
		   testBuffer = new StringBuilder();
	   }
   }
	// You need to create more test cases for your Partitions if you need to
	
	// This function receives ExceptionInitializerError and receives junit.framework.AssertionFailedError
	// Fails at result = urlVal.isValid(url) in the validateUrl() function
	// This function tests different URLs with each instance the for loop by passing in (random) valid indices of each ResultPair array that
	// holds a single part of the URL to the validateURL function, where validateUrl takes these indices to build and test each URL combination.
	public void testIsValid() {
		Random rand = new Random();
	    System.out.println("testIsValid1 tests:");
	    UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	    int failCount = 0;
	    for (int i = 0; i < 10; i++) {
	    	if(!validateUrl(urlVal, rand.nextInt(testUrlScheme.length), rand.nextInt(testUrlAuthority.length),  rand.nextInt(testUrlPort.length), rand.nextInt(testPath.length), rand.nextInt(testUrlQuery.length))) {
	    		failCount++;
	    	}
	    	
	    }
	    if(failCount > 0) {
	    	fail("testIsValid function has failed");
	    }else {
	    	   System.out.println("testIsValid function has passed!");
	    }
	       
	}
	// This function tests different URLs with each instance of the for loop by passing in valid indices of each ResultPair array that
	// holds a single part of the URL to the validateURL function, where validateUrl takes these indices to build and test each URL combination.
	public void testIsValid1() {
       System.out.println("testIsValid tests:");
       UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
       int failCount = 0;
       for (int schemeIdx = 0; schemeIdx < testUrlScheme.length; schemeIdx++) {
           for (int authIdx = 0; authIdx < testUrlAuthority.length; authIdx++) {
               for (int portIdx = 0; portIdx < testUrlPort.length; portIdx++) {
                   for (int pathIdx = 0; pathIdx < testPath.length; pathIdx++) {
                       for (int queryIdx = 0; queryIdx < testUrlQuery.length; queryIdx++) {
                           if(!validateUrl(urlVal, schemeIdx, authIdx, portIdx, pathIdx, queryIdx)) {
                        	   failCount++;
                           }
                       }
                   }
               }
           }
       }
       if(failCount > 0) {
           fail("testIsValid1 function has failed");
       }
       else {
    	   System.out.println("testIsValid1 function has passed!");
       }
       
   }
	// This function receives valid indices of each ResultPair array that holds a single part of the URL.
	// validateUrl takes these indices to build and test each URL and tests to seee if the urlVal.isValid() method is working properly.
	public boolean validateUrl(UrlValidator urlVal, int schemeIdx, int authIdx, int portIdx, int pathIdx, int queryIdx) {
		System.out.println("In validateUrl\n");
		String url = testUrlScheme[schemeIdx].item + testUrlAuthority[authIdx].item + testUrlPort[portIdx].item + testPath[pathIdx].item + testUrlQuery[queryIdx].item;
		System.out.println(url);
        boolean expected = testUrlScheme[schemeIdx].valid && testUrlAuthority[authIdx].valid && testUrlPort[portIdx].valid && testPath[pathIdx].valid && testUrlQuery[queryIdx].valid,
				 result = urlVal.isValid(url);
        assertEquals(url, expected, result);
        System.out.println("Expected: " + result +  " Result: "+  expected);
        if(result != expected) {
        	System.out.println("TEST FAILED WITH URL: " + url + " EXPECTED: " + expected + " RESULT: " + result);
        	return false;
        }
        return true;
   }
	
}
