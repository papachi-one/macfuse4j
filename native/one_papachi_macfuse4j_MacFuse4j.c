#include "one_papachi_macfuse4j_MacFuse4j.h"

#include <stdio.h>
#include <fuse.h>
#include <string.h>
#include <stdlib.h>

static JavaVM *jvm;

static int macfuse4j_getattr(const char *path, struct stat *stbuf) {
    JNIEnv *env;
    (*jvm)->AttachCurrentThread(jvm, (void**) &env, NULL);
    jobject callbackObject = fuse_get_context()->private_data;
    jstring jFileName = (*env)->NewStringUTF(env, path);
    jclass class = (*env)->GetObjectClass(env, callbackObject);
    jmethodID methodId = (*env)->GetMethodID(env, class, "getattr", "(Ljava/lang/String;)Lone/papachi/macfuse4j/results/GetattrResult;");
    (*env)->DeleteLocalRef(env, class);
    jobject result = (*env)->CallObjectMethod(env, callbackObject, methodId, jFileName);
    class = (*env)->GetObjectClass(env, result);
    methodId = (*env)->GetMethodID(env, class, "status", "()I");
    jint status = (*env)->CallIntMethod(env, result, methodId);
    methodId = (*env)->GetMethodID(env, class, "mode", "()I");
    jint mode = (*env)->CallIntMethod(env, result, methodId);
    methodId = (*env)->GetMethodID(env, class, "nlink", "()I");
    jint nlink = (*env)->CallIntMethod(env, result, methodId);
    methodId = (*env)->GetMethodID(env, class, "uid", "()I");
    jint uid = (*env)->CallIntMethod(env, result, methodId);
    methodId = (*env)->GetMethodID(env, class, "gid", "()I");
    jint gid = (*env)->CallIntMethod(env, result, methodId);
    methodId = (*env)->GetMethodID(env, class, "size", "()J");
    jlong size = (*env)->CallLongMethod(env, result, methodId);
    methodId = (*env)->GetMethodID(env, class, "atime", "()J");
    jlong atime = (*env)->CallLongMethod(env, result, methodId);
    methodId = (*env)->GetMethodID(env, class, "mtime", "()J");
    jlong mtime = (*env)->CallLongMethod(env, result, methodId);
    methodId = (*env)->GetMethodID(env, class, "ctime", "()J");
    jlong ctime = (*env)->CallLongMethod(env, result, methodId);
    memset(stbuf, 0, sizeof(struct stat));
    stbuf->st_mode = mode;
    stbuf->st_nlink = nlink;
    stbuf->st_uid = uid;
    stbuf->st_gid = gid;
    stbuf->st_size = size;
    stbuf->st_atimespec.tv_sec = atime;
    stbuf->st_mtimespec.tv_sec = mtime;
    stbuf->st_ctimespec.tv_sec = ctime;
    (*env)->DeleteLocalRef(env, class);
    (*env)->DeleteLocalRef(env, jFileName);
    (*jvm)->DetachCurrentThread(jvm);
    return status;
}

static int macfuse4j_create(const char *path, mode_t mode, struct fuse_file_info *fi) {
    JNIEnv *env;
    (*jvm)->AttachCurrentThread(jvm, (void**) &env, NULL);
    jobject callbackObject = fuse_get_context()->private_data;
    jstring jFileName = (*env)->NewStringUTF(env, path);
    jint jmode = mode;
    jclass class = (*env)->GetObjectClass(env, callbackObject);
    jmethodID methodId = (*env)->GetMethodID(env, class, "create", "(Ljava/lang/String;I)Lone/papachi/macfuse4j/results/CreateResult;");
    (*env)->DeleteLocalRef(env, class);
    jobject result = (*env)->CallObjectMethod(env, callbackObject, methodId, jFileName, jmode);
    class = (*env)->GetObjectClass(env, result);
    methodId = (*env)->GetMethodID(env, class, "status", "()I");
    (*env)->DeleteLocalRef(env, class);
    jint status = (*env)->CallIntMethod(env, result, methodId);
    (*env)->DeleteLocalRef(env, jFileName);
    (*jvm)->DetachCurrentThread(jvm);
    return status;
}

static int macfuse4j_open(const char *path, struct fuse_file_info *fi) {
    JNIEnv *env;
    (*jvm)->AttachCurrentThread(jvm, (void**) &env, NULL);
    jobject callbackObject = fuse_get_context()->private_data;
    jstring jFileName = (*env)->NewStringUTF(env, path);
    jclass class = (*env)->GetObjectClass(env, callbackObject);
    jmethodID methodId = (*env)->GetMethodID(env, class, "open", "(Ljava/lang/String;)Lone/papachi/macfuse4j/results/OpenResult;");
    (*env)->DeleteLocalRef(env, class);
    jobject result = (*env)->CallObjectMethod(env, callbackObject, methodId, jFileName);
    class = (*env)->GetObjectClass(env, result);
    methodId = (*env)->GetMethodID(env, class, "status", "()I");
    (*env)->DeleteLocalRef(env, class);
    jint status = (*env)->CallIntMethod(env, result, methodId);
    (*env)->DeleteLocalRef(env, jFileName);
    (*jvm)->DetachCurrentThread(jvm);
    return status;
}

static int macfuse4j_read(const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *fi) {
    JNIEnv *env;
    (*jvm)->AttachCurrentThread(jvm, (void**) &env, NULL);
    jobject callbackObject = fuse_get_context()->private_data;
    jstring jFileName = (*env)->NewStringUTF(env, path);
    jobject jbuffer = (*env)->NewDirectByteBuffer(env, buf, size);
    jlong joffset = offset;
    jclass class = (*env)->GetObjectClass(env, callbackObject);
    jmethodID methodId = (*env)->GetMethodID(env, class, "read", "(Ljava/lang/String;Ljava/nio/ByteBuffer;J)Lone/papachi/macfuse4j/results/ReadResult;");
    (*env)->DeleteLocalRef(env, class);
    jobject result = (*env)->CallObjectMethod(env, callbackObject, methodId, jFileName, jbuffer, joffset);
    class = (*env)->GetObjectClass(env, result);
    methodId = (*env)->GetMethodID(env, class, "status", "()I");
    (*env)->DeleteLocalRef(env, class);
    jint status = (*env)->CallIntMethod(env, result, methodId);
    (*env)->DeleteLocalRef(env, jbuffer);
    (*env)->DeleteLocalRef(env, jFileName);
    (*jvm)->DetachCurrentThread(jvm);
    return status;
}

static int macfuse4j_write(const char *path, const char *buf, size_t size, off_t offset, struct fuse_file_info *fi) {
    JNIEnv *env;
    (*jvm)->AttachCurrentThread(jvm, (void**) &env, NULL);
    jobject callbackObject = fuse_get_context()->private_data;
    jstring jFileName = (*env)->NewStringUTF(env, path);
    jobject jbuffer = (*env)->NewDirectByteBuffer(env, (void *) buf, size);
    jlong joffset = offset;
    jclass class = (*env)->GetObjectClass(env, callbackObject);
    jmethodID methodId = (*env)->GetMethodID(env, class, "write", "(Ljava/lang/String;Ljava/nio/ByteBuffer;J)Lone/papachi/macfuse4j/results/WriteResult;");
    (*env)->DeleteLocalRef(env, class);
    jobject result = (*env)->CallObjectMethod(env, callbackObject, methodId, jFileName, jbuffer, joffset);
    class = (*env)->GetObjectClass(env, result);
    methodId = (*env)->GetMethodID(env, class, "status", "()I");
    (*env)->DeleteLocalRef(env, class);
    jint status = (*env)->CallIntMethod(env, result, methodId);
    (*env)->DeleteLocalRef(env, jbuffer);
    (*env)->DeleteLocalRef(env, jFileName);
    (*jvm)->DetachCurrentThread(jvm);
    return status;
}

static int macfuse4j_truncate(const char *path, off_t size) {
    JNIEnv *env;
    (*jvm)->AttachCurrentThread(jvm, (void**) &env, NULL);
    jobject callbackObject = fuse_get_context()->private_data;
    jstring jFileName = (*env)->NewStringUTF(env, path);
    jlong jsize = size;
    jclass class = (*env)->GetObjectClass(env, callbackObject);
    jmethodID methodId = (*env)->GetMethodID(env, class, "truncate", "(Ljava/lang/String;J)Lone/papachi/macfuse4j/results/TruncateResult;");
    (*env)->DeleteLocalRef(env, class);
    jobject result = (*env)->CallObjectMethod(env, callbackObject, methodId, jFileName, jsize);
    class = (*env)->GetObjectClass(env, result);
    methodId = (*env)->GetMethodID(env, class, "status", "()I");
    (*env)->DeleteLocalRef(env, class);
    jint status = (*env)->CallIntMethod(env, result, methodId);
    (*env)->DeleteLocalRef(env, jFileName);
    (*jvm)->DetachCurrentThread(jvm);
    return status;
}

static int macfuse4j_unlink(const char *path) {
    JNIEnv *env;
    (*jvm)->AttachCurrentThread(jvm, (void**) &env, NULL);
    jobject callbackObject = fuse_get_context()->private_data;
    jstring jFileName = (*env)->NewStringUTF(env, path);
    jclass class = (*env)->GetObjectClass(env, callbackObject);
    jmethodID methodId = (*env)->GetMethodID(env, class, "unlink", "(Ljava/lang/String;)Lone/papachi/macfuse4j/results/UnlinkResult;");
    (*env)->DeleteLocalRef(env, class);
    jobject result = (*env)->CallObjectMethod(env, callbackObject, methodId, jFileName);
    class = (*env)->GetObjectClass(env, result);
    methodId = (*env)->GetMethodID(env, class, "status", "()I");
    (*env)->DeleteLocalRef(env, class);
    jint status = (*env)->CallIntMethod(env, result, methodId);
    (*env)->DeleteLocalRef(env, jFileName);
    (*jvm)->DetachCurrentThread(jvm);
    return status;
}

static int macfuse4j_mkdir(const char *path, mode_t mode) {
    JNIEnv *env;
    (*jvm)->AttachCurrentThread(jvm, (void**) &env, NULL);
    jobject callbackObject = fuse_get_context()->private_data;
    jstring jFileName = (*env)->NewStringUTF(env, path);
    jint jmode = mode;
    jclass class = (*env)->GetObjectClass(env, callbackObject);
    jmethodID methodId = (*env)->GetMethodID(env, class, "mkdir", "(Ljava/lang/String;)Lone/papachi/macfuse4j/results/MkdirResult;");
    (*env)->DeleteLocalRef(env, class);
    jobject result = (*env)->CallObjectMethod(env, callbackObject, methodId, jFileName, jmode);
    class = (*env)->GetObjectClass(env, result);
    methodId = (*env)->GetMethodID(env, class, "status", "()I");
    (*env)->DeleteLocalRef(env, class);
    jint status = (*env)->CallIntMethod(env, result, methodId);
    (*env)->DeleteLocalRef(env, jFileName);
    (*jvm)->DetachCurrentThread(jvm);
    return status;
}

static int macfuse4j_readdir(const char *path, void *buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi) {
    JNIEnv *env;
    (*jvm)->AttachCurrentThread(jvm, (void**) &env, NULL);
    jobject callbackObject = fuse_get_context()->private_data;
    jstring jFileName = (*env)->NewStringUTF(env, path);
    jclass class = (*env)->GetObjectClass(env, callbackObject);
    jmethodID methodId = (*env)->GetMethodID(env, class, "readdir", "(Ljava/lang/String;)Lone/papachi/macfuse4j/results/ReaddirResult;");
    jobject result = (*env)->CallObjectMethod(env, callbackObject, methodId, jFileName);
    (*env)->DeleteLocalRef(env, class);
    class = (*env)->GetObjectClass(env, result);
    methodId = (*env)->GetMethodID(env, class, "status", "()I");
    jint status = (*env)->CallIntMethod(env, result, methodId);
    methodId = (*env)->GetMethodID(env, class, "result", "()Ljava/util/Iterator;");
    jobject iterator = (*env)->CallObjectMethod(env, result, methodId);
    (*env)->DeleteLocalRef(env, class);
    class = (*env)->GetObjectClass(env, iterator);
    jmethodID methodIdHasNext = (*env)->GetMethodID(env, class, "hasNext", "()Z");
    jmethodID methodIdNext = (*env)->GetMethodID(env, class, "next", "()Ljava/lang/Object;");
    (*env)->DeleteLocalRef(env, class);
    struct stat stbuf;
    while ((*env)->CallBooleanMethod(env, iterator, methodIdHasNext) == JNI_TRUE) {
        jobject dirEntry = (*env)->CallObjectMethod(env, iterator, methodIdNext);
        class = (*env)->GetObjectClass(env, dirEntry);
        methodId = (*env)->GetMethodID(env, class, "fileName", "()Ljava/lang/String;");
        jstring filename = (*env)->CallObjectMethod(env, dirEntry, methodId);
        methodId = (*env)->GetMethodID(env, class, "mode", "()I");
        jint mode = (*env)->CallIntMethod(env, dirEntry, methodId);
        methodId = (*env)->GetMethodID(env, class, "nlink", "()I");
        jint nlink = (*env)->CallIntMethod(env, dirEntry, methodId);
        methodId = (*env)->GetMethodID(env, class, "uid", "()I");
        jint uid = (*env)->CallIntMethod(env, dirEntry, methodId);
        methodId = (*env)->GetMethodID(env, class, "gid", "()I");
        jint gid = (*env)->CallIntMethod(env, dirEntry, methodId);
        methodId = (*env)->GetMethodID(env, class, "size", "()J");
        jlong size = (*env)->CallLongMethod(env, dirEntry, methodId);
        methodId = (*env)->GetMethodID(env, class, "atime", "()J");
        jlong atime = (*env)->CallLongMethod(env, dirEntry, methodId);
        methodId = (*env)->GetMethodID(env, class, "mtime", "()J");
        jlong mtime = (*env)->CallLongMethod(env, dirEntry, methodId);
        methodId = (*env)->GetMethodID(env, class, "ctime", "()J");
        jlong ctime = (*env)->CallLongMethod(env, dirEntry, methodId);
        jint length = (*env)->GetStringUTFLength(env, filename);
        const char * utfChars = (*env)->GetStringUTFChars(env, filename, NULL);
        char *name = malloc((length + 1) * sizeof(char));
        memcpy(name, utfChars, length);
        name[length] = 0;
        stbuf.st_mode = mode;
        stbuf.st_nlink = nlink;
        stbuf.st_uid = uid;
        stbuf.st_gid = gid;
        stbuf.st_size = size;
        stbuf.st_atimespec.tv_sec = atime;
        stbuf.st_mtimespec.tv_sec = mtime;
        stbuf.st_ctimespec.tv_sec = ctime;
        filler(buf, name, &stbuf, 0);
        free(name);
        (*env)->ReleaseStringUTFChars(env, filename, utfChars);
        (*env)->DeleteLocalRef(env, filename);
        (*env)->DeleteLocalRef(env, class);
        (*env)->DeleteLocalRef(env, dirEntry);
    }
    (*env)->DeleteLocalRef(env, jFileName);
    (*jvm)->DetachCurrentThread(jvm);
    return status;
}

static int macfuse4j_rmdir(const char *path) {
    JNIEnv *env;
    (*jvm)->AttachCurrentThread(jvm, (void**) &env, NULL);
    jobject callbackObject = fuse_get_context()->private_data;
    jstring jFileName = (*env)->NewStringUTF(env, path);
    jclass class = (*env)->GetObjectClass(env, callbackObject);
    jmethodID methodId = (*env)->GetMethodID(env, class, "rmdir", "(Ljava/lang/String;)Lone/papachi/macfuse4j/results/RmdirResult;");
    (*env)->DeleteLocalRef(env, class);
    jobject result = (*env)->CallObjectMethod(env, callbackObject, methodId, jFileName);
    class = (*env)->GetObjectClass(env, result);
    methodId = (*env)->GetMethodID(env, class, "status", "()I");
    (*env)->DeleteLocalRef(env, class);
    jint status = (*env)->CallIntMethod(env, result, methodId);
    (*env)->DeleteLocalRef(env, jFileName);
    (*jvm)->DetachCurrentThread(jvm);
    return status;
}

static int macfuse4j_rename(const char *from, const char *to) {
    JNIEnv *env;
    (*jvm)->AttachCurrentThread(jvm, (void**) &env, NULL);
    jobject callbackObject = fuse_get_context()->private_data;
    jstring jFileName = (*env)->NewStringUTF(env, from);
    jstring jNewFileName = (*env)->NewStringUTF(env, to);
    jclass class = (*env)->GetObjectClass(env, callbackObject);
    jmethodID methodId = (*env)->GetMethodID(env, class, "rename", "(Ljava/lang/String;Ljava/lang/String;)Lone/papachi/macfuse4j/results/RenameResult;");
    (*env)->DeleteLocalRef(env, class);
    jobject result = (*env)->CallObjectMethod(env, callbackObject, methodId, jFileName, jNewFileName);
    class = (*env)->GetObjectClass(env, result);
    methodId = (*env)->GetMethodID(env, class, "status", "()I");
    (*env)->DeleteLocalRef(env, class);
    jint status = (*env)->CallIntMethod(env, result, methodId);
    (*env)->DeleteLocalRef(env, jNewFileName);
    (*env)->DeleteLocalRef(env, jFileName);
    (*jvm)->DetachCurrentThread(jvm);
    return status;
}

static int macfuse4j_chmod(const char *path, mode_t mode) {
    JNIEnv *env;
    (*jvm)->AttachCurrentThread(jvm, (void**) &env, NULL);
    jobject callbackObject = fuse_get_context()->private_data;
    jstring jFileName = (*env)->NewStringUTF(env, path);
    jint mod = mode;
    jclass class = (*env)->GetObjectClass(env, callbackObject);
    jmethodID methodId = (*env)->GetMethodID(env, class, "chmod", "(Ljava/lang/String;I)Lone/papachi/macfuse4j/results/ChmodResult;");
    (*env)->DeleteLocalRef(env, class);
    jobject result = (*env)->CallObjectMethod(env, callbackObject, methodId, jFileName, mod);
    class = (*env)->GetObjectClass(env, result);
    methodId = (*env)->GetMethodID(env, class, "status", "()I");
    (*env)->DeleteLocalRef(env, class);
    jint status = (*env)->CallIntMethod(env, result, methodId);
    (*env)->DeleteLocalRef(env, jFileName);
    (*jvm)->DetachCurrentThread(jvm);
    return status;
}

static int macfuse4j_chown(const char *path, uid_t uid, gid_t gid) {
    JNIEnv *env;
    (*jvm)->AttachCurrentThread(jvm, (void**) &env, NULL);
    jobject callbackObject = fuse_get_context()->private_data;
    jstring jFileName = (*env)->NewStringUTF(env, path);
    jint userid = uid;
    jint groupid = gid;
    jclass class = (*env)->GetObjectClass(env, callbackObject);
    jmethodID methodId = (*env)->GetMethodID(env, class, "chown", "(Ljava/lang/String;II)Lone/papachi/macfuse4j/results/ChownResult;");
    (*env)->DeleteLocalRef(env, class);
    jobject result = (*env)->CallObjectMethod(env, callbackObject, methodId, jFileName, userid, groupid);
    class = (*env)->GetObjectClass(env, result);
    methodId = (*env)->GetMethodID(env, class, "status", "()I");
    (*env)->DeleteLocalRef(env, class);
    jint status = (*env)->CallIntMethod(env, result, methodId);
    (*env)->DeleteLocalRef(env, jFileName);
    (*jvm)->DetachCurrentThread(jvm);
    return status;
}

static int macfuse4j_utimens(const char *path, const struct timespec ts[2]) {
    JNIEnv *env;
    (*jvm)->AttachCurrentThread(jvm, (void**) &env, NULL);
    jobject callbackObject = fuse_get_context()->private_data;
    jstring jFileName = (*env)->NewStringUTF(env, path);
    jlong atime = 0;
    jlong mtime = 0;
    if (ts != NULL) {
        if (ts[0].tv_nsec == UTIME_NOW) {
        } else if (ts[0].tv_nsec == UTIME_OMIT) {
            atime = -1;
        } else {
            atime = ts[0].tv_sec;
        }
        if (ts[1].tv_nsec == UTIME_NOW) {
        } else if (ts[1].tv_nsec == UTIME_OMIT) {
            mtime = -1;
        } else {
            mtime = ts[1].tv_sec;
        }
    }
    jclass class = (*env)->GetObjectClass(env, callbackObject);
    jmethodID methodId = (*env)->GetMethodID(env, class, "utimens", "(Ljava/lang/String;JJ)Lone/papachi/macfuse4j/results/UtimentsResult;");
    (*env)->DeleteLocalRef(env, class);
    jobject result = (*env)->CallObjectMethod(env, callbackObject, methodId, jFileName, atime, mtime);
    class = (*env)->GetObjectClass(env, result);
    methodId = (*env)->GetMethodID(env, class, "status", "()I");
    (*env)->DeleteLocalRef(env, class);
    jint status = (*env)->CallIntMethod(env, result, methodId);
    (*env)->DeleteLocalRef(env, jFileName);
    (*jvm)->DetachCurrentThread(jvm);
    return status;
}

static const struct fuse_operations macfuse4j_operations = {
        .getattr = macfuse4j_getattr,
        .create = macfuse4j_create,
        .open = macfuse4j_open,
        .read = macfuse4j_read,
        .write = macfuse4j_write,
        .truncate = macfuse4j_truncate,
        .unlink = macfuse4j_unlink,
        .mkdir = macfuse4j_mkdir,
        .readdir = macfuse4j_readdir,
        .rmdir = macfuse4j_rmdir,
        .rename = macfuse4j_rename,
        .chmod = macfuse4j_chmod,
        .chown = macfuse4j_chown,
        .utimens = macfuse4j_utimens
};

JNIEXPORT jint JNICALL Java_one_papachi_macfuse4j_MacFuse4j_mount(JNIEnv *env, jobject thisObj, jobjectArray args) {
    (*env)->GetJavaVM(env, &jvm);
    int argc = (*env)->GetArrayLength(env, args);
    char *argv[argc];
    for (int i = 0; i < argc; ++i) {
        jstring string = (*env)->GetObjectArrayElement(env, args, i);
        jint length = (*env)->GetStringUTFLength(env, string);
        const char * utfChars = (*env)->GetStringUTFChars(env, string, NULL);
        char *arg = malloc((length + 1) * sizeof(char));
        memcpy(arg, utfChars, length);
        arg[length] = 0;
        argv[i] = arg;
        (*env)->ReleaseStringUTFChars(env, string, utfChars);
        (*env)->DeleteLocalRef(env, string);
    }
    return fuse_main(argc, argv, &macfuse4j_operations, thisObj);
}