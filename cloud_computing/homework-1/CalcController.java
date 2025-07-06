package edu.ecu.cs.seng6285.restfulbots;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class CalcController {
    private static final String logClass = "CalcController";
    private final Logger logger = LoggerFactory.getLogger(logClass);

    @GetMapping("/add")
    private String add(int n, int m) {
        logger.info(String.format("Added %d and %d", n, m));
        return String.format("Added %d and %d with result %d", n, m, n + m);
    }

    @GetMapping("/subtract")
    private String sub(int n, int m) {
        logger.info(String.format("Subtracted %d from %d", m, n));
        return String.format("Subtracted %d from %d with result %d", m, n, n - m);
    }

    @GetMapping("/times")
    private String times(int n, int m) {
        logger.info(String.format("Multiplied %d by %d", n, m));
        return String.format("Multiplied %d by %d with result %d", n, m, n * m);
    }

    @GetMapping("/div")
    private String divide(int n, int m) {
        logger.info(String.format("Divided %d by %d", n, m));
        return String.format("Divided %d by %d with result %d", n, m, n / m);
    }

    @GetMapping("/neg")
    private String negate(int n) {
        logger.info(String.format("Negated %d", n));
        return String.format("Negated %d with result %d", n, n * -1);
    }
}