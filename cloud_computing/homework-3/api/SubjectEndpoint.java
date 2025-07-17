package edu.ecu.cs.seng6285.restfulbots.api;

import java.util.ArrayList;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import edu.ecu.cs.seng6285.restfulbots.datastore.SubjectService;
import edu.ecu.cs.seng6285.restfulbots.models.Subject;

@RestController
@RequestMapping(value = "/subjects")
public class SubjectEndpoint {
    @Autowired
    private SubjectService subjectService;

    @GetMapping
    public List<Subject> getAllSubjects() {
        // TODO: What code is needed here to return all subjects?
        return subjectService.getAllSubjects();

        // TODO: You can remove this return statement once you are returning something valid.
        // return Collections.emptyList();
    }

    @GetMapping(value = "/init")
    public boolean initSubjects() {
        // Create some sample subjects
        List<Subject> subjects = new ArrayList<>();

        subjects.add(new Subject.Builder()
            .withSubjectName("Computer Science")
            .build()
        );
        subjects.add(new Subject.Builder()
            .withSubjectName("Mathematics")
            .build()
        );
        subjects.add(new Subject.Builder()
            .withSubjectName("English")
            .build()
        );
        subjects.add(new Subject.Builder()
            .withSubjectName("History")
            .build()
        );

        // TODO: Is something missing here? If so, add the missing code...
        for (Subject subject : subjects) {
            subjectService.createSubject(subject);
        }

        return true;
    }
}