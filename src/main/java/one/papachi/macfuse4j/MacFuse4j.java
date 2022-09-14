package one.papachi.macfuse4j;

import one.papachi.macfuse4j.results.*;

import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.ByteBuffer;
import java.nio.file.Paths;

public class MacFuse4j {

    private static final String temporaryLibraryPath = System.getProperty("java.io.tmpdir");

    private static final String library = "libmacfuse4j.dylib";

    static {
        File file = Paths.get(temporaryLibraryPath, library).toFile();
        try (InputStream is = MacFuse4j.class.getResourceAsStream(library); OutputStream os = new FileOutputStream(file)) {
            is.transferTo(os);
        } catch (Exception e) {
        }
        file.deleteOnExit();
        System.load(file.getAbsolutePath());
    }

    public GetattrResult getattr(String fileName) {
        return null;
    }

    public CreateResult create(String fileName, int mode) {
        return null;
    }

    public OpenResult open(String fileName) {
        return null;
    }

    public ReadResult read(String fileName, ByteBuffer buffer, long offset) {
        return null;
    }

    public WriteResult write(String fileName, ByteBuffer buffer, long offset) {
        return null;
    }

    public TruncateResult truncate(String fileName, long size) {
        return null;
    }

    public UnlinkResult unlink(String fileName) {
        return null;
    }

    public MkdirResult mkdir(String fileName) {
        return null;
    }

    public ReaddirResult readdir(String fileName) {
        return null;
    }

    public RmdirResult rmdir(String fileName) {
        return null;
    }

    public RenameResult rename(String fileName, String newFileName) {
        return null;
    }

    public ChmodResult chmod(String fileName, int mode) {
        return null;
    }

    public ChownResult chown(String fileName, int uid, int gid) {
        return null;
    }

    public UtimentsResult utimens(String filename, long atime, long mtime) {
        return null;
    }

    public native int mount(String... args);

}
