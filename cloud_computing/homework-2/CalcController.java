package edu.ecu.cs.seng6285.restfulbots;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class CalcController {
    private static String logClass = "CalcController";
    private Logger logger = LoggerFactory.getLogger(logClass);
    
    @GetMapping("/square")
    private int square(int n) {
        logger.info(String.format("Requested to square %d", n));
        return n * n;
    }

    @GetMapping("/add")
    private int add(int n, int m) {
        logger.info(String.format("Requested to add %d to %d", n, m));
        return n + m;
    }

    @GetMapping("/subtract")
    private int subtract(int n, int m) {
        logger.info(String.format("Requested to subtract %d from %d", m, n));
        return n - m;
    }

    @GetMapping("/times")
    private int times(int n, int m) {
        logger.info(String.format("Requested to multiply %d by %d", n, m));
        return n * m;
    }

    @GetMapping("/div")
    private int div(int n, int m) {
        logger.info(String.format("Requested to divide %d by %d", n, m));
        return n / m;
    }

    @GetMapping("/neg")
    private int neg(int n) {
        logger.info(String.format("Requested to negate %d", n));
        return -n;
    }
}
