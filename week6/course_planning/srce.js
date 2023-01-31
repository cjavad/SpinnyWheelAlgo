let courseCount = 0;
let courseDependents = []

process.stdin.on('data', function (data) {
    data.toString().split('\n').forEach(function (line) {
        if (line === '') return;
        const [course_a, course_b] = line.toString().split(' ').map(x => Number(x.trim()));

        if (courseCount == 0) {
            courseCount = course_a;
            courseDependents = new Array(course_b);
            return;
        }
        
        if (!courseDependents[course_a]) courseDependents[course_a] = [];
        courseDependents[course_a].push(course_b);
    });
});

process.stdin.on('end', function () {
    console.table(courseDependents);
    // solve();
});

function findOne(haystack, arr) {
    return arr.some(v => {
        return haystack.indexOf(v) >= 0;
    });
}

function solve() {
    let semester = 0;
    let currentAvailable = all_courses.filter(course => !courses.hasOwnProperty(course));

    while (currentAvailable.length > 0) {
        let nextAvailable = [];
        // Find all courses that depend on the current available courses
        for (let i = 0; i < Object.keys(courses).length; i++) {
            courses[Object.keys(courses)[i]].some(v => {
                const hasOne = (currentAvailable.indexOf(v) >= 0);
                if (hasOne) delete courses[Object.keys(courses)[i]][courses[Object.keys(courses)[i]].indexOf(v)];
                return hasOne;
            });
        }

        if (courses[course].length == 0) {
            nextAvailable.push(course);
            delete courses[course];
        }

        currentAvailable = nextAvailable;
        semester++;
    }


    console.log(semester);
}