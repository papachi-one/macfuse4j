package one.papachi.macfuse4j.results;

public record DirEntry(String fileName, int mode, int nlink, int uid, int gid, long size, long atime, long mtime, long ctime) {
}
