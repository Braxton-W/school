package edu.ecu.cs.seng6285.restfulbots.datastore;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import org.springframework.stereotype.Service;

import com.google.cloud.datastore.Datastore;
import com.google.cloud.datastore.DatastoreOptions;
import com.google.cloud.datastore.Entity;
import com.google.cloud.datastore.Key;
import com.google.cloud.datastore.KeyFactory;
import com.google.cloud.datastore.Query;
import com.google.cloud.datastore.QueryResults;
import com.google.cloud.datastore.StructuredQuery;

import edu.ecu.cs.seng6285.restfulbots.models.Subject;

@Service
public class SubjectService {
    private Datastore datastore = DatastoreOptions.getDefaultInstance().getService();
    private static final String ENTITY_KIND = "Subject";
    private final KeyFactory keyFactory = datastore.newKeyFactory().setKind(ENTITY_KIND);

    public Key createSubject(Subject subject) {
        // TODO: What code needs to be added here to create a subject?
        Key key = datastore.allocateId(keyFactory.newKey());
        Entity subjectEntity = Entity.newBuilder(key)
                .set(Subject.SUBJECT_NAME, subject.getSubjectName())
                .build();
        datastore.put(subjectEntity);

        System.out.println("Created " + subject.getSubjectName());

        return key;
    }

    public List<Subject> getAllSubjects() {
        // TODO: What code needs to be added here to retrieve all subjects?
        Query<Entity> query = Query.newEntityQueryBuilder()
                .setKind(ENTITY_KIND)
                .build();

        Iterator<Entity> entities = datastore.run(query);
        return buildSubjects(entities);

        /* QueryResults<Entity> results = datastore.run(query);
        List<Subject> subjects = new ArrayList<>();

        while (results.hasNext()) {
            Entity entity = results.next();
            Subject subject = new Subject();
            subject.setSubjectName(entity.getString(Subject.SUBJECT_NAME));
            subjects.add(subject);
        }
        
        return subjects; */

        // TODO: Remove this return statement once you have something valid to return
        // return Collections.emptyList();
    }

    // TODO: What support methods are needed here?
    // Feel free to look at the other service classes for inspiration.
    public Subject getSubjectByName(String subjectName) {
        Query<Entity> query = Query.newEntityQueryBuilder()
            .setKind(ENTITY_KIND)
            .setFilter(StructuredQuery.PropertyFilter.eq(Subject.SUBJECT_NAME, subjectName))
            .build();

        QueryResults<Entity> results = datastore.run(query);

        if (results.hasNext()) {
            return entityToSubject(results.next());
        }

        return null;
    }

    private List<Subject> buildSubjects(Iterator<Entity> entities) {
        List<Subject> subjects = new ArrayList<>();
        entities.forEachRemaining(entity -> subjects.add(entityToSubject(entity)));
        return subjects;
    }

    private Subject entityToSubject(Entity entity) {
        return new Subject.Builder()
                .withSubjectName(entity.getString(Subject.SUBJECT_NAME))
                .build();
    }
}
