## Docker Activity

Run a container based on the hello-world image.

What command did you use to create and run a container based on the latest hello-world image? `docker run hello-world`
    
What is the output of running this command?
```md
Hello from Docker!
This message shows that your installation appears to be working correctly.

To generate this message, Docker took the following steps:
 1. The Docker client contacted the Docker daemon.
 2. The Docker daemon pulled the "hello-world" image from the Docker Hub.
    (amd64)
 3. The Docker daemon created a new container from that image which runs the
    executable that produces the output you are currently reading.
 4. The Docker daemon streamed that output to the Docker client, which sent it
    to your terminal.

To try something more ambitious, you can run an Ubuntu container with:
 $ docker run -it ubuntu bash

Share images, automate workflows, and more with a free Docker ID:
 https://hub.docker.com/

For more examples and ideas, visit:
 https://docs.docker.com/get-started/
```
You now want to run a container based on Ubuntu 20.04. You want to run this interactively, so you can access the shell.

What command would you use to run this container? `docker run -it ubuntu:20.04`

Inside this container, create a new file named myfile.txt. You don't need to put anything in it, but feel free to. Now, exit the container. `touch myfile.txt`

Using the same command as you used for #3, start an Ubuntu 20.04 container again.
Do you see myfile.txt? Why or why not?

> No, we are within a different container from where we created myfile.txt.

Can you restart the container you created in Step 3? Hint, look at the docker start command and the docker ps command. Once you restart the container, do you see the file you created?

> `docker start -i OLD_CONTAINER_NAME` restarts the container where myfile.txt exists.

At this point, we would like to use MySQL. Wouldn't it be nice if, instead of installing it locally, based on our OS, we could just use Docker for this? Let's try: https://hub.docker.com/_/mysqlLinks to an external site.

Start up a detached container running MySQL. You can use the latest release, and you should give the container a name.

What command did you use to start the container running MySQL? `docker run --name mysqldb -e MYSQL_ROOT_PASSWORD=password -d mysql:latest`

Now, since you started in detached mode, you cannot run MySQL commands. To actually use it, you should instead start an interactive terminal for the same container. Hint: look at the Docker exec command.

What command did you use to start the terminal? `docker exec -it mysqldb bash`

Now that you have a terminal, you can connect to the database. To do so, run `mysql -u root -p`. When prompted for a password, enter the root password you set in Step 7 (if you didn't do this, look back at Docker Hub to see how to start the container). Now, you can actually create a database. Let's set up a simple database using the following commands:
```mysql
create database sample;
use sample;
create table users(username varchar(30) not null, password varchar(30) not null, email varchar(50));
insert into users values('user1', 'snEAk3', 'user1@coldmail.com');
select * from users;
exit;
```
At this point, we have a database with some (very basic!) initial data. You can type exit to leave the container.

So far, so good. We have a database, and we can store data. There is one problem, though -- the data is in the container. That isn't great if we lose the container. Can we store the data outside the container so that even if we lose the container, we still have the data?

> Yes

Create a Docker volume. This is described in Chapter 4 of Docker in Action, which you can access here: https://www.manning.com/books/docker-in-action-second-editionLinks to an external site. You should create a volume called mysqldata that will store the data. Hint: look at the docker volume command. You can find more information about this command here: https://docs.docker.com/storage/volumes/Links to an external site. Note that this page also includes the details you need to create and use volumes.

What command did you use to create the new volume? `docker volume create sqlvolume`

Now, create the MySQL container again. In this case, though, you want to give it a new name, and you want to map the mysqldata volume to directory /var/lib/mysql, which is where the database files are kept. With this in mind, start the container again (remember, it should be detached).

What command did you use to start the MySQL container? `docker exec -it mysqldb2 bash`

Run through Step 9 again to connect to your new container and create a table.
```mysql
create database sample;
use sample;
create table users(username varchar(30) not null, password varchar(30) not null, email varchar(50));
insert into users values('user1', 'snEAk3', 'user1@coldmail.com');
select * from users;
exit;
```

Now, stop and remove the new MySQL container you created. Look at the `docker stop` and `docker rm` commands for details.

What command did you use to stop the MySQL container? `docker stop mysqldb4`

What command did you use to remove the MySQL container? `docker rm mysqldb4`

Finally, repeat Step 11. Then, using similar commands to Step 12, connect to the container and the database. Enter the following commands:
```mysql
use sample;
select * from users;
```
Do you see data returned by the query, or error messages?

> Data returned by query
